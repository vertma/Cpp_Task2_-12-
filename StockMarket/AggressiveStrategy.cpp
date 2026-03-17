#include "AggressiveStrategy.h"

AggressiveStrategy::AggressiveStrategy(double m)
    : Strategy(m, "Агрессивная") {}

bool AggressiveStrategy::wantBuy(const std::string& stock, double price) {
    if (lastPrice.count(stock) == 0) {
        return false;
    }
    double previousPrice = lastPrice.at(stock);
    return price < previousPrice * 0.93;
}

bool AggressiveStrategy::wantSell(double price, double buyPrice) {
    return price > buyPrice;
}