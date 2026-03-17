#include "Quote.h"

Quote::Quote(const std::string& name, int d, int m, int y, double p)
    : stockName(name), date(d, m, y), price(p) {}