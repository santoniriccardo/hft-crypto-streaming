#include "ccapi_cpp/ccapi_session.h"

namespace ccapi {
Logger* Logger::logger = nullptr;  // This line is needed.
class MyEventHandler : public EventHandler {
 public:
  bool processEvent(const Event& event, Session* session) override {
    if (event.getType() == Event::Type::SUBSCRIPTION_DATA) {
      for (const auto& message : event.getMessageList()) {
        std::cout << message.toString() << std::endl;
        std::cout << std::string("Best bid and ask at ") + UtilTime::getISOTimestamp(message.getTime()) + " are:" << std::endl;
        for (const auto& element : message.getElementList()) {
          const std::map<std::string, std::string>& elementNameValueMap = element.getNameValueMap();
          std::cout << "  " + toString(elementNameValueMap) << std::endl;

          if (element.has("BID_PRICE")) {
            bestBidPrice = std::stod(element.getValue("BID_PRICE"));
          }
          
          if (element.has("BID_SIZE")) {
            bestBidSize = std::stod(element.getValue("BID_SIZE"));
          }

          if (element.has("ASK_PRICE")) {
            bestAskPrice = std::stod(element.getValue("ASK_PRICE"));
          }

          if (element.has("ASK_SIZE")) {
            bestAskSize = std::stod(element.getValue("ASK_SIZE"));
          }
        }
        double midpoint = ((bestBidPrice * bestAskSize) + (bestAskPrice * bestBidSize)) / (bestBidSize + bestAskSize);
        std::cout << "Current Midpoint Valuation: " << midpoint << std::endl;
      } 
    }
    return true;
  }
  double bestBidPrice;
  double bestBidSize;
  double bestAskPrice;
  double bestAskSize;
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
  subscriptionList.emplace_back("coinbase", "ETH-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=1", "c");
  session.subscribe(subscriptionList);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  session.stop();
  std::cout << "Bye" << std::endl;
  return EXIT_SUCCESS;
}
