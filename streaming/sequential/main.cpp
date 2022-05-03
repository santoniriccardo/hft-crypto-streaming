#include "ccapi_cpp/ccapi_session.h"
#include "valuation_engine.h"
#include "market_data_parser.h"

namespace ccapi {
Logger* Logger::logger = nullptr;  // This line is needed.
class SequentialEventHandler : public EventHandler {
 public:
    SequentialEventHandler(MarketDataParser marketDataParser, ValuationEngine valuationEngine) : marketDataParser(marketDataParser), valuationEngine(valuationEngine), count(0) {}

  bool processEvent(const Event& event, Session* session) override {
    if (event.getType() == Event::Type::SUBSCRIPTION_DATA) {
      for (const auto& message : event.getMessageList()) {

        std::vector<Order> bids;
        std::vector<Order> asks;

        marketDataParser.parse(message, bids, asks);

        double valuation = valuationEngine.priceAsset(bids, asks);
        // std::cout << "Valuation: " << valuation << std::endl;
        count++;
      }
    }
    return true;
  }
    int count;

  private:
    MarketDataParser marketDataParser;
    ValuationEngine valuationEngine;
};
} /* namespace ccapi */
using ::ccapi::SequentialEventHandler;
using ::ccapi::Session;
using ::ccapi::SessionConfigs;
using ::ccapi::SessionOptions;
using ::ccapi::Subscription;
using ::ccapi::toString;
int main(int argc, char** argv) {
  SessionOptions sessionOptions;
  SessionConfigs sessionConfigs;

  // Instantiate necessary market data parser/valuation engine.
  MarketDataParser marketDataParser;
  ValuationEngine valuationEngine;

  SequentialEventHandler eventHandler(marketDataParser, valuationEngine);
  Session session(sessionOptions, sessionConfigs, &eventHandler);
  std::vector<Subscription> subscriptionList;

  // BTC Subscriptions
  subscriptionList.emplace_back("binance", "BTCUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b");
  subscriptionList.emplace_back("binance-us", "BTCUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-us");
  subscriptionList.emplace_back("bitfinex", "tBTCUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bf");
  subscriptionList.emplace_back("bitmex", "XBTUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bm");
  subscriptionList.emplace_back("bitstamp", "btcusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bs");
  subscriptionList.emplace_back("coinbase", "BTC-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "c");
  subscriptionList.emplace_back("cryptocom", "BTC_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "cc");
  subscriptionList.emplace_back("gemini", "btcusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "g");

  // ETH Subscriptions
  subscriptionList.emplace_back("binance", "ETHUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-eth");
  subscriptionList.emplace_back("binance-us", "ETHUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-us-eth");
  subscriptionList.emplace_back("bitfinex", "tETHUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bf-eth");
  subscriptionList.emplace_back("bitmex", "ETHUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bm-eth");
  subscriptionList.emplace_back("bitstamp", "ethusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bs-eth");
  subscriptionList.emplace_back("coinbase", "ETH-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "c-eth");
  subscriptionList.emplace_back("cryptocom", "ETH_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "cc-eth");
  subscriptionList.emplace_back("gemini", "ethusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "g-eth");
  
  // LINK Subscriptions
  subscriptionList.emplace_back("binance", "LINKUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-link");
  subscriptionList.emplace_back("binance-us", "LINKUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-us-link");
  subscriptionList.emplace_back("bitfinex", "tLINKUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bf-link");
  subscriptionList.emplace_back("bitmex", "LINKUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bm-link");
  subscriptionList.emplace_back("bitstamp", "linkusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bs-link");
  subscriptionList.emplace_back("coinbase", "LINK-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "c-link");
  subscriptionList.emplace_back("cryptocom", "LINK_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "cc-link");
  subscriptionList.emplace_back("gemini", "linkusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "g-link");
  
  // SOL Subscriptions
  subscriptionList.emplace_back("binance", "SOLUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-sol");
  subscriptionList.emplace_back("binance-us", "SOLUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-us-sol");
  subscriptionList.emplace_back("bitfinex", "tSOLUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bf-sol");
  subscriptionList.emplace_back("bitmex", "SOLUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bm-sol");
  subscriptionList.emplace_back("bitstamp", "solusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bs-sol");
  subscriptionList.emplace_back("coinbase", "SOL-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "c-sol");
  subscriptionList.emplace_back("cryptocom", "SOL_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "cc-sol");
  subscriptionList.emplace_back("gemini", "solusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "g-sol");
  
  // XRP Subscriptions
  subscriptionList.emplace_back("binance", "XRPUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-xrp");
  subscriptionList.emplace_back("binance-us", "XRPUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "b-us-xrp");
  subscriptionList.emplace_back("bitfinex", "tXRPUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bf-xrp");
  subscriptionList.emplace_back("bitmex", "XRPUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bm-xrp");
  subscriptionList.emplace_back("bitstamp", "xrpusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "bs-xrp");
  subscriptionList.emplace_back("coinbase", "XRP-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "c-xrp");
  subscriptionList.emplace_back("cryptocom", "XRP_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "cc-xrp");
  subscriptionList.emplace_back("gemini", "xrpusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=100", "g-xrp");


  session.subscribe(subscriptionList);
  std::this_thread::sleep_for(std::chrono::seconds(10));
  session.stop();
  
  std::cout << "Throughput: " << eventHandler.count << " market data events" << std::endl;
  return EXIT_SUCCESS;
}
