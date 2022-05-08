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

public:
    Date(unsigned year, unsigned month, unsigned day) : year(year), month(month), day(day){};

    unsigned getYear() const { return year; }
    unsigned getMonth() const { return month; }
    unsigned getDay() const { return day; }

    friend std::istream &operator>>(std::istream &is, Date &date);
};

std::ostream &operator<<(std::ostream &os, Date const &date);

#endif