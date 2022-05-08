#include <iostream>
#include <fstream>
#include <assert.h>

#include "Date.hpp"

bool Date::isLeap(unsigned year)
{
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

bool Date::validDate(unsigned year, unsigned month, unsigned day)
{
    bool thirtyOneDayMonth = (month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12);

    return (month != 0 && day != 0) && ((day <= 31 && thirtyOneDayMonth) ||
                                        (month == 2 && ((day <= 29 && isLeap(year)) || (day <= 28 && !isLeap(year)))) ||
                                        (day <= 30 && !thirtyOneDayMonth));
}

Date::Date(unsigned year, unsigned month, unsigned day)
{
    assert(validDate(year, month, day));
    this->year = year;
    this->month = month;
    this->day = day;
}

std::istream &operator>>(std::istream &is, Date &date)
{
    return (is >> date.year >> date.month >> date.day);
}

std::ostream &operator<<(std::ostream &os, Date const &date)
{
    return os << date.getYear() << '-' << date.getMonth() << '-' << date.getDay() << '\n';
}