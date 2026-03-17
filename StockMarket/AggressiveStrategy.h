#pragma once
#include "Strategy.h"

class AggressiveStrategy : public Strategy {
public:
    AggressiveStrategy(double m);

    bool wantBuy(const std::string& stock, double price) override;
    bool wantSell(double price, double buyPrice) override;
};