#pragma once
#include <string>
#include "Date.h"

struct Position {
    std::string name;
    double buyPrice;
    Date buyDate;
    int count;

    Position(const std::string& n, double p, const Date& d, int c);
};