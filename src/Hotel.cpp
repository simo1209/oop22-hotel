#include "Hotel.hpp"

bool Hotel::isRoomTakenDuringPeriod(Date start, Date end, unsigned roomId){
    for (unsigned i = 0; i < reservationsCount; ++i)
    {
        if (reservations[i].getRoomId() == roomId && (start < reservations[i].getEnd()))
        {
            return true;
        }
    }
    return false;    
}