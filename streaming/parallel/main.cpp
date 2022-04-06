#include "ccapi_cpp/ccapi_session.h"
#include <thread>

namespace ccapi {
Logger* Logger::logger = nullptr;  // This line is needed.
class MyEventHandler : public EventHandler {
 public:
  bool processEvent(const Event& event, Session* session) override {
    if (event.getType() == Event::Type::SUBSCRIPTION_DATA) {
      for (const auto& message : event.getMessageList()) {
        std::cout << "Thread Id: " << std::this_thread::get_id() << " " << std::string("Best bid and ask at ") + UtilTime::getISOTimestamp(message.getTime()) + " are:" << std::endl;
        for (const auto& element : message.getElementList()) {
          const std::map<std::string, std::string>& elementNameValueMap = element.getNameValueMap();
          std::cout << "  " + toString(elementNameValueMap) << std::endl;
        }
      }
    }
    return true;
  }
};
} /* namespace ccapi */
using ::ccapi::MyEventHandler;
using ::ccapi::Session;
using ::ccapi::EventDispatcher;
using ::ccapi::SessionConfigs;
using ::ccapi::SessionOptions;
using ::ccapi::Subscription;
using ::ccapi::toString;
int main(int argc, char** argv) {
  SessionOptions sessionOptions;
  SessionConfigs sessionConfigs;
  MyEventHandler eventHandler;
  EventDispatcher eventDispatcher(8);

  Session session(sessionOptions, sessionConfigs, &eventHandler, &eventDispatcher);
  std::vector<Subscription> subscriptionList;
  subscriptionList.emplace_back("binance", "BTCUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "b");
  subscriptionList.emplace_back("binance-us", "BTCUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "b-us");
  subscriptionList.emplace_back("bitfinex", "tBTCUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "bf");
  subscriptionList.emplace_back("bitmex", "XBTUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "bm");
  subscriptionList.emplace_back("bitstamp", "btcusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "bs");
  subscriptionList.emplace_back("coinbase", "BTC-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "c");
  subscriptionList.emplace_back("cryptocom", "BTC_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "cc");
  subscriptionList.emplace_back("gemini", "btcusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "g");

  subscriptionList.emplace_back("binance", "ETHUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "b-eth");
  subscriptionList.emplace_back("binance-us", "ETHUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "b-us-eth");
  subscriptionList.emplace_back("bitfinex", "tETHUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "bf-eth");
  subscriptionList.emplace_back("bitmex", "ETHUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "bm-eth");
  subscriptionList.emplace_back("bitstamp", "ethusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "bs-eth");
  subscriptionList.emplace_back("coinbase", "ETH-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "c-eth");
  subscriptionList.emplace_back("cryptocom", "ETH_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "cc-eth");
  subscriptionList.emplace_back("gemini", "ethusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=10", "g-eth");


  session.subscribe(subscriptionList);
  std::this_thread::sleep_for(std::chrono::seconds(100));
  session.stop();
  std::cout << "Bye" << std::endl;
  return EXIT_SUCCESS;
}
