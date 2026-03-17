#pragma once
#include "Strategy.h"

class ConservativeStrategy : public Strategy {
public:
    ConservativeStrategy(double m);

    bool wantBuy(const std::string& stock, double price) override;
    bool wantSell(double price, double buyPrice) override;
};