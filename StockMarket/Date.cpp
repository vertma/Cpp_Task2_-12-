#include "Date.h"

Date::Date(int d, int m, int y)
    : day(d), month(m), year(y) {}

bool Date::isSameDay(const Date& other) const {
    return day == other.day
        && month == other.month
        && year == other.year;
}