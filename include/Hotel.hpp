#include "Room.hpp"
#include "Date.hpp"
#include "Reservation.hpp"

#ifndef __HOTEL_HPP
#define __HOTEL_HPP

class Hotel
{
protected:
    size_t roomsCount;
    Room *rooms;
    size_t reservationsCount;
    Reservation *reservations;

    bool hasRoomWithId(unsigned roomId);
    bool isRoomTakenDuringPeriod(Date &start, Date &end, unsigned roomId);
    Room findOpenRoom(Date &start, Date &end, unsigned bedCount);

    virtual void loadRooms() = 0;
    virtual void loadReservations() = 0;

public:
    size_t getRoomsCount() { return roomsCount; }
    size_t getReservationsCount() { return reservationsCount; }

    virtual void createReservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservatorName) = 0;
    virtual void listFreeRooms(Date &date) = 0;
    // virtual void releaseRoom(unsigned roomId) = 0;
    virtual void reservationInquiry(Date &periodStart, Date &periodEnd) = 0;
    virtual void printOpenRoom(Date &start, Date &end, unsigned bedCount) = 0;
};

#endif