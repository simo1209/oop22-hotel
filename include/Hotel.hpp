#include "Room.hpp"
#include "Date.hpp"
#include "Reservation.hpp"

#ifndef __HOTEL_HPP
#define __HOTEL_HPP

class Hotel
{
protected:
    size_t roomsCount;
    Room *const rooms;
    size_t reservationsCount;
    Reservation *const reservations;

    virtual void loadRooms() = 0;
    virtual void loadReservations() = 0;

    virtual void createReservation(Date &start, Date &end, Room &room, char const * note, char const *reservatorName = "") = 0;
    virtual void listFreeRooms(Date &date) = 0;
    virtual void releaseRoom(unsigned roomId) = 0;
    virtual void reservationInquiry(Date &start, Date &end) = 0;
    virtual Room findOpenRoom(Date start, Date end, unsigned bedCount) = 0;
};

#endif