#include "ccapi_cpp/ccapi_session.h"
#include <chrono>
#include <execution>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

namespace ccapi {
Logger* Logger::logger = nullptr;  // This line is needed.
class MyEventHandler : public EventHandler {
 public:
  MyEventHandler() {
    numVolumes = 10;
  }

  bool processEvent(const Event& event, Session* session) override {
    if (event.getType() == Event::Type::SUBSCRIPTION_DATA) {
      for (const auto& message : event.getMessageList()) {
        std::cout << std::string("Best bid and ask at ") + UtilTime::getISOTimestamp(message.getTime()) + " are:" << std::endl;
        
        // Ordered on best bid/ask respectively
        std::vector<std::pair<double, double>> bids; // Decreasing
        std::vector<std::pair<double, double>> asks; // Increasing
        
        bidVolume = 0;
        askVolume = 0;

        for (const auto& element : message.getElementList()) {
          const std::map<std::string, std::string>& elementNameValueMap = element.getNameValueMap();
          std::cout << "  " + toString(elementNameValueMap) << std::endl;

          if (element.has("BID_PRICE") && element.has("BID_SIZE")) {
            std::pair<double, double> bid = std::make_pair(std::stod(element.getValue("BID_PRICE")), std::stod(element.getValue("BID_SIZE")));
            bids.push_back(bid);
            bidVolume += bid.second;
          }
        
          if (element.has("ASK_PRICE") && element.has("ASK_SIZE")) {
            std::pair<double, double> ask = std::make_pair(std::stod(element.getValue("ASK_PRICE")), std::stod(element.getValue("ASK_SIZE")));
            asks.push_back(ask);
            askVolume += ask.second;
          }
        }

        double totalVolume = std::min(bidVolume, askVolume) / 2;
        double incVolume = totalVolume / numVolumes;

        std::cout << "Total Volume: " << totalVolume << " Increment Volume: " << incVolume << std::endl;

        std::vector<double> bidVolumeAvgCosts;
        std::vector<double> askVolumeAvgCosts;


        auto meanPricePerVolume = [incVolume] (std::vector<std::pair<double, double>> &orders, std::vector<double> &avgCosts, int numVolumes) {
          
          double curVolume;
          double curWeightedPrice;
          for (int i = 0; i < numVolumes; i++) {
            curVolume = 0;
            double curWeightedTotal = i == 0 ? 0 : avgCosts.back() * (i * incVolume);
            

            while (curVolume < incVolume) {
              double remaining = incVolume - curVolume;

              std::pair<double, double> bestOrder = orders.front();

              double matchedVolume = std::min(remaining, bestOrder.second);
              
              curWeightedTotal += matchedVolume * bestOrder.first;

              // If we matched all of the best order, lets remove it
              if (matchedVolume == bestOrder.second) {
                orders.erase(orders.begin());
              } else {
                // Else simply remove volume taken at this level
                bestOrder.second -= matchedVolume;
              }

              curVolume += matchedVolume;
            }

            // std::cout << "Pushing: " << curWeightedTotal / (incVolume * (i + 1)) << std::endl;
            avgCosts.push_back(curWeightedTotal / (incVolume * (i + 1)));
          }
        };

        meanPricePerVolume(bids, bidVolumeAvgCosts, numVolumes);
        meanPricePerVolume(asks, askVolumeAvgCosts, numVolumes);

        std::cout << "Calculated mean price per volume" << std::endl;

        auto avg = [] (std::vector<double> input) {
          double total = 0;
          for (const auto i : input) {
            total += i;
          }
          std::cout << "avg size: " << input.size() << std::endl;
          return total / input.size();
        };
        double avgBids = avg(bidVolumeAvgCosts);
        double avgAsks = avg(askVolumeAvgCosts);

        std::cout << "Avg Bids: " << avgBids << std::endl;
        std::cout << "Avg Asks: " << avgAsks << std::endl;

        double valuation = (avgBids + avgAsks) / 2;
        std::cout << "Current Valuation: " <<  valuation << std::endl;
        
      }
    }
    return true;
  }

  int numVolumes;


  double bidVolume;
  double askVolume;
};
} /* namespace ccapi */
using ::ccapi::MyEventHandler;
using ::ccapi::Session;
using ::ccapi::SessionConfigs;
using ::ccapi::SessionOptions;
using ::ccapi::Subscription;
using ::ccapi::toString;
int main(int argc, char** argv) {
  SessionOptions sessionOptions;
  SessionConfigs sessionConfigs;
  MyEventHandler eventHandler;
  Session session(sessionOptions, sessionConfigs, &eventHandler);
  std::vector<Subscription> subscriptionList;
  subscriptionList.emplace_back("cryptocom", "ETH_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=40", "cc");
  session.subscribe(subscriptionList);
  std::this_thread::sleep_for(std::chrono::seconds(100));
  session.stop();
  std::cout << "Bye" << std::endl;
  return EXIT_SUCCESS;
}
