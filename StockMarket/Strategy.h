#pragma once
#include <string>
#include <vector>
#include <map>
#include "Date.h"
#include "Position.h"

class Strategy {
protected:
    double money;
    std::vector<Position> portfolio;
    std::string name;
    std::map<std::string, double> lastPrice;

    bool canSell(const Position& pos, const Date& today) const;

public:
    Strategy(double startMoney, const std::string& n);

    virtual ~Strategy();

    virtual bool wantBuy(const std::string& stock, double price) = 0;

    virtual bool wantSell(double price, double buyPrice) = 0;

    void onQuote(const std::string& stock, double price, const Date& today);

    double getMoney() const;

    std::string getName() const;
};
