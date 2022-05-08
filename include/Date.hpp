#include <istream>
#include <ostream>

#ifndef __DATE_HPP
#define __DATE_HPP

class Date
{
private:
    unsigned year;
    unsigned month;
    unsigned day;

    static bool isLeap(unsigned year);
    static bool validDate(unsigned year, unsigned month, unsigned day);

public:
    Date(unsigned year = 2022, unsigned month = 5, unsigned day = 8);

    unsigned getYear() const { return year; }
    unsigned getMonth() const { return month; }
    unsigned getDay() const { return day; }

    friend std::istream &operator>>(std::istream &is, Date &date);
};

std::ostream &operator<<(std::ostream &os, Date const &date);

#endif