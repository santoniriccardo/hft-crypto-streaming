#include "ccapi_cpp/ccapi_session.h"
#include "valuation_engine.h"
#include "market_data_parser.h"
#include <atomic>

namespace ccapi {
Logger* Logger::logger = nullptr;  // This line is needed.
class ParallelEventHandler : public EventHandler {
 public:
    ParallelEventHandler(MarketDataParser marketDataParser, ValuationEngine valuationEngine) : marketDataParser(marketDataParser), valuationEngine(valuationEngine) {
      count = 0;
    }

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
    std::atomic<int> count;

  private:
    MarketDataParser marketDataParser;
    ValuationEngine valuationEngine;
};

} /* namespace ccapi */
using ::ccapi::ParallelEventHandler;
using ::ccapi::EventDispatcher;
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

  ParallelEventHandler eventHandler(marketDataParser, valuationEngine);
  
  EventDispatcher eventDispatcher(8);

  Session session(sessionOptions, sessionConfigs, &eventHandler, &eventDispatcher);

  std::vector<Subscription> subscriptionList;
  
  
  // BTC Subscriptions
  subscriptionList.emplace_back("binance", "BTCUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b");
  subscriptionList.emplace_back("binance-us", "BTCUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us");
  subscriptionList.emplace_back("bitfinex", "tBTCUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf");
  subscriptionList.emplace_back("bitmex", "XBTUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm");
  subscriptionList.emplace_back("bitstamp", "btcusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs");
  subscriptionList.emplace_back("coinbase", "BTC-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c");
  subscriptionList.emplace_back("cryptocom", "BTC_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc");
  subscriptionList.emplace_back("gemini", "btcusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g");
  subscriptionList.emplace_back("erisx", "BTC/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-btc");
  subscriptionList.emplace_back("ftx", "BTC/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-btc");
  subscriptionList.emplace_back("ftx-us", "BTC/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-btc");
  subscriptionList.emplace_back("kucoin", "BTC-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-btc");
  subscriptionList.emplace_back("ascendex", "BTC/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-btc");


  // ETH Subscriptions
  subscriptionList.emplace_back("binance", "ETHUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-eth");
  subscriptionList.emplace_back("binance-us", "ETHUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us-eth");
  subscriptionList.emplace_back("bitfinex", "tETHUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf-eth");
  subscriptionList.emplace_back("bitmex", "ETHUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm-eth");
  subscriptionList.emplace_back("bitstamp", "ethusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs-eth");
  subscriptionList.emplace_back("coinbase", "ETH-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c-eth");
  subscriptionList.emplace_back("cryptocom", "ETH_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc-eth");
  subscriptionList.emplace_back("gemini", "ethusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g-eth");
  subscriptionList.emplace_back("erisx", "ETH/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-eth");
  subscriptionList.emplace_back("ftx", "ETH/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-eth");
  subscriptionList.emplace_back("ftx-us", "ETH/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-eth");
  subscriptionList.emplace_back("kucoin", "ETH-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-eth");
  subscriptionList.emplace_back("ascendex", "ETH/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-eth");
  
  // LINK Subscriptions
  subscriptionList.emplace_back("binance", "LINKUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-link");
  subscriptionList.emplace_back("binance-us", "LINKUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us-link");
  subscriptionList.emplace_back("bitfinex", "tLINKUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf-link");
  subscriptionList.emplace_back("bitmex", "LINKUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm-link");
  subscriptionList.emplace_back("bitstamp", "linkusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs-link");
  subscriptionList.emplace_back("coinbase", "LINK-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c-link");
  subscriptionList.emplace_back("cryptocom", "LINK_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc-link");
  subscriptionList.emplace_back("gemini", "linkusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g-link");
  subscriptionList.emplace_back("erisx", "LINK/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-link");
  subscriptionList.emplace_back("ftx", "LINK/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-link");
  subscriptionList.emplace_back("ftx-us", "LINK/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-link");
  subscriptionList.emplace_back("kucoin", "LINK-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-link");
  subscriptionList.emplace_back("ascendex", "LINK/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-link");
  
  // SOL Subscriptions
  subscriptionList.emplace_back("binance", "SOLUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-sol");
  subscriptionList.emplace_back("binance-us", "SOLUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us-sol");
  subscriptionList.emplace_back("bitfinex", "tSOLUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf-sol");
  subscriptionList.emplace_back("bitmex", "SOLUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm-sol");
  subscriptionList.emplace_back("bitstamp", "solusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs-sol");
  subscriptionList.emplace_back("coinbase", "SOL-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c-sol");
  subscriptionList.emplace_back("cryptocom", "SOL_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc-sol");
  subscriptionList.emplace_back("gemini", "solusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g-sol");
  subscriptionList.emplace_back("erisx", "SOL/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-sol");
  subscriptionList.emplace_back("ftx", "SOL/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-sol");
  subscriptionList.emplace_back("ftx-us", "SOL/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-sol");
  subscriptionList.emplace_back("kucoin", "SOL-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-sol");
  subscriptionList.emplace_back("ascendex", "SOL/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-sol");
  
  // XRP Subscriptions
  subscriptionList.emplace_back("binance", "XRPUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-xrp");
  subscriptionList.emplace_back("binance-us", "XRPUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us-xrp");
  subscriptionList.emplace_back("bitfinex", "tXRPUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf-xrp");
  subscriptionList.emplace_back("bitmex", "XRPUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm-xrp");
  subscriptionList.emplace_back("bitstamp", "xrpusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs-xrp");
  subscriptionList.emplace_back("coinbase", "XRP-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c-xrp");
  subscriptionList.emplace_back("cryptocom", "XRP_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc-xrp");
  subscriptionList.emplace_back("gemini", "xrpusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g-xrp");
  subscriptionList.emplace_back("erisx", "XRP/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-xrp");
  subscriptionList.emplace_back("ftx", "XRP/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-xrp");
  subscriptionList.emplace_back("ftx-us", "XRP/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-xrp");
  subscriptionList.emplace_back("kucoin", "XRP-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-xrp");
  subscriptionList.emplace_back("ascendex", "XRP/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-xrp");

  // DOT Subscriptions
  subscriptionList.emplace_back("binance", "DOTUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-dot");
  subscriptionList.emplace_back("binance-us", "DOTUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us-dot");
  subscriptionList.emplace_back("bitfinex", "tDOTUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf-dot");
  subscriptionList.emplace_back("bitmex", "DOTUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm-dot");
  subscriptionList.emplace_back("bitstamp", "dotusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs-dot");
  subscriptionList.emplace_back("coinbase", "DOT-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c-dot");
  subscriptionList.emplace_back("cryptocom", "DOT_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc-dot");
  subscriptionList.emplace_back("gemini", "dotusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g-dot");
  subscriptionList.emplace_back("erisx", "DOT/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-dot");
  subscriptionList.emplace_back("ftx", "DOT/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-dot");
  subscriptionList.emplace_back("ftx-us", "DOT/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-dot");
  subscriptionList.emplace_back("kucoin", "DOT-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-dot");
  subscriptionList.emplace_back("ascendex", "DOT/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-dot");

  // DOGE Subscriptions
  subscriptionList.emplace_back("binance", "DOGEUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-doge");
  subscriptionList.emplace_back("binance-us", "DOGEUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us-doge");
  subscriptionList.emplace_back("bitfinex", "tDOGEUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf-doge");
  subscriptionList.emplace_back("bitmex", "DOGEUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm-doge");
  subscriptionList.emplace_back("bitstamp", "dogeusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs-doge");
  subscriptionList.emplace_back("coinbase", "DOGE-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c-doge");
  subscriptionList.emplace_back("cryptocom", "DOGE_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc-doge");
  subscriptionList.emplace_back("gemini", "dogeusd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g-doge");
  subscriptionList.emplace_back("erisx", "DOGE/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-doge");
  subscriptionList.emplace_back("ftx", "DOGE/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-doge");
  subscriptionList.emplace_back("ftx-us", "DOGE/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-doge");
  subscriptionList.emplace_back("kucoin", "DOGE-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-doge");
  subscriptionList.emplace_back("ascendex", "DOGE/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-doge");

  // ADA Subscriptions
  subscriptionList.emplace_back("binance", "ADAUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-ada");
  subscriptionList.emplace_back("binance-us", "ADAUSDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "b-us-ada");
  subscriptionList.emplace_back("bitfinex", "tADAUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bf-ada");
  subscriptionList.emplace_back("bitmex", "ADAUSD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bm-ada");
  subscriptionList.emplace_back("bitstamp", "adausd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "bs-ada");
  subscriptionList.emplace_back("coinbase", "ADA-USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "c-ada");
  subscriptionList.emplace_back("cryptocom", "ADA_USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "cc-ada");
  subscriptionList.emplace_back("gemini", "adausd", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "g-ada");
  subscriptionList.emplace_back("erisx", "ADA/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "e-ada");
  subscriptionList.emplace_back("ftx", "ADA/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-ada");
  subscriptionList.emplace_back("ftx-us", "ADA/USD", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "f-us-ada");
  subscriptionList.emplace_back("kucoin", "ADA-USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "ku-ada");
  subscriptionList.emplace_back("ascendex", "ADA/USDT", "MARKET_DEPTH", "MARKET_DEPTH_MAX=20", "a-ada");


  session.subscribe(subscriptionList);
  std::this_thread::sleep_for(std::chrono::seconds(10));

  session.stop();
  eventDispatcher.stop();
  
  std::cout << "Throughput: " << eventHandler.count << " market data events" << std::endl;
  return EXIT_SUCCESS;
}
