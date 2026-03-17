#pragma once

struct Date {
    int day;
    int month;
    int year;

    Date(int d, int m, int y);

    bool isSameDay(const Date& other) const;
};