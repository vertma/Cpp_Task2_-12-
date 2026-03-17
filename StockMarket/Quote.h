#pragma once
#include <string>
#include "Date.h"

struct Quote {
    std::string stockName;
    Date date;
    double price;

    Quote(const std::string& name, int d, int m, int y, double p);
};