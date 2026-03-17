#include "Position.h"

Position::Position(const std::string& n, double p, const Date& d, int c)
    : name(n), buyPrice(p), buyDate(d), count(c) {}