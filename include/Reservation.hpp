#include "Date.hpp"
#include "Room.hpp"

#ifndef __RESERVATION_HPP
#define __RESERVATION_HPP

class Reservation
{
private:
    Date start;
    Date end;
    unsigned roomId;

public:
    Reservation(Date &start, Date &end, unsigned roomId) {}
    ~Reservation() {}

    Date getStart() const { return start; }
    Date getEnd() const { return end; }
    unsigned getRoomId() const { return roomId; }

    friend std::istream &operator>>(std::istream &is, Reservation &reservation);
};

std::ostream &operator<<(std::ostream &os, Reservation const &reservation);

#endif