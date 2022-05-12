#include "Hotel.hpp"

bool Hotel::hasRoomWithId(unsigned roomId){
    for (unsigned i = 0; i < roomsCount; ++i)
    {
        if (rooms[i].getRoomId() == roomId)
        {
            return true;
        }
    }
    return false;    
}

bool Hotel::isRoomTakenDuringPeriod(Date start, Date end, unsigned roomId)
{
    for (unsigned i = 0; i < reservationsCount; ++i)
    {
        if (reservations[i].getRoomId() == roomId && start <= reservations[i].getEnd() && end >= reservations[i].getStart())
        {
            return true;
        }
    }
    return false;
}