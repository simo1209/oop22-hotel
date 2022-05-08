#include <iostream>
#include <fstream>

#include "Date.hpp"

std::istream &operator>>(std::istream &is, Date &date)
{
    return (is >> date.year >> date.month >> date.day);
}

std::ostream &operator<<(std::ostream &os, Date const &date)
{
    return os << date.getYear() << '-' << date.getMonth() << '-' << date.getDay() << '\n';
}