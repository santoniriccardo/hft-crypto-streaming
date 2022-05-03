#ifndef VALUATION_ENGINE_H_
#define VALUATION_ENGINE_H_

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

using ::ccapi::toString;
class ValuationEngine {
    public:
    
    double priceAsset(std::vector<Order> &bids, std::vector<Order> &asks) const { 
        double valuation = 0.0;
        int numVolumes = 20;

        // Aggregate current volume on each side of order book
        double bidVolume = totalVolume(bids);
        double askVolume = totalVolume(asks);

        // Determine total volume in calculation, and increment volume depending on number of levels        
        double totalVolume = (3 * std::min(bidVolume, askVolume)) / 4;
        double incVolume = totalVolume / numVolumes;

        std::vector<double> bidVolumeAvgCosts;
        std::vector<double> askVolumeAvgCosts;

        // Calculate the mean price paid per level of volume
        meanPricePerVolume(bids, bidVolumeAvgCosts, numVolumes, incVolume);
        meanPricePerVolume(asks, askVolumeAvgCosts, numVolumes, incVolume);
        
        // Aggregate the average price paid across volume levels on either side of order book
        double avgBids = avg(bidVolumeAvgCosts);
        double avgAsks = avg(askVolumeAvgCosts);
        
        valuation = (avgBids + avgAsks) / 2;
        return valuation;
    }

    private:
        void meanPricePerVolume(std::vector<Order> &orders, std::vector<double> &avgCosts, int numVolumes, double incVolume) const {
            double curVolume;
            double curWeightedPrice;
            for (int i = 0; i < numVolumes; i++) {
                curVolume = 0;
                double curWeightedTotal = i == 0 ? 0 : avgCosts.back() * (i * incVolume);
                

                while (curVolume < incVolume) {
                double remaining = incVolume - curVolume;

                Order& bestOrder = orders.front();

                double matchedVolume = std::min(remaining, bestOrder.getVolume());
                
                curWeightedTotal += matchedVolume * bestOrder.getPrice();

                // If we matched all of the best order, lets remove it
                if (matchedVolume == bestOrder.getVolume()) {
                    orders.erase(orders.begin());
                } else {
                    // Else simply remove volume taken at this level
                    bestOrder.setVolume(bestOrder.getVolume() - matchedVolume);
                }

                curVolume += matchedVolume;
                }

                avgCosts.push_back(curWeightedTotal / (incVolume * (i + 1)));
            }
        }

        double totalVolume(std::vector<Order> &orders) const {
            double total = 0.0;

            for (const Order &order : orders) {
                total += order.getVolume();
            }

            return total;
        }

        double avg(std::vector<double> &input) const {
            double total = 0.0;
            for (const auto i : input) {
                total += i;
            }
            return total / input.size();
        }
};

#endif  // VALUATION_ENGINE_H_
