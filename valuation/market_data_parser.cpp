#include <vector>
#include <numeric>
#include <functional>
#include "order.h"
#include <chrono>
#include <execution>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
#include "ccapi_cpp/ccapi_message.h"

class MarketDataParser {
    public:
    
    void parseMarketData(Message &message, std::vector<Order> &bids, std::vector<Order> &asks) {
        for (const auto& element : message.getElementList()) {
          const std::map<std::string, std::string>& elementNameValueMap = element.getNameValueMap();
          std::cout << "  " + toString(elementNameValueMap) << std::endl;

          if (element.has("BID_PRICE") && element.has("BID_SIZE")) {
            Order bid = new Order(std::stod(element.getValue("BID_PRICE")), std::stod(element.getValue("BID_SIZE")), OrderType::BID);
            bids.push_back(bid);
          }
        
          if (element.has("ASK_PRICE") && element.has("ASK_SIZE")) {
            Order bid = new Order(std::stod(element.getValue("ASK_PRICE")), std::stod(element.getValue("ASK_SIZE")), OrderType::BID);
            asks.push_back(ask);
          }
        }
    }
    
};