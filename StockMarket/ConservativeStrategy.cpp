#include "ConservativeStrategy.h"

ConservativeStrategy::ConservativeStrategy(double m)
    : Strategy(m, "Консервативная") {}

bool ConservativeStrategy::wantBuy(const std::string& stock, double price) {
    if (lastPrice.count(stock) == 0) {
        return false;
    }
    double previousPrice = lastPrice.at(stock);
    return price < previousPrice * 0.97;
}

bool ConservativeStrategy::wantSell(double price, double buyPrice) {
    return price > buyPrice * 1.05;
}