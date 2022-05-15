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

public:
    Date(unsigned year = 2022, unsigned month = 5, unsigned day = 8);

    unsigned getYear() const { return year; }
    unsigned getMonth() const { return month; }
    unsigned getDay() const { return day; }

    static bool validDate(unsigned year, unsigned month, unsigned day);

    friend bool operator<(Date const &left, Date const &right);
    friend bool operator>(Date const &left, Date const &right) { return right < left; };
    friend bool operator<=(Date const &left, Date const &right) { return !(left > right); };
    friend bool operator>=(Date const &left, Date const &right) { return !(left < right); };

    friend std::istream &operator>>(std::istream &is, Date &date);
};

std::ostream &operator<<(std::ostream &os, Date const &date);

#endif