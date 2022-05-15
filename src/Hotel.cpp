#include <assert.h>

#include "Hotel.hpp"
#include "Exceptions.hpp"

bool Hotel::hasRoomWithId(unsigned roomId)
{
    for (unsigned i = 0; i < roomsCount; ++i)
    {
        if (rooms[i].getRoomId() == roomId)
        {
            return true;
        }
    }
    return false;
}

bool Hotel::isRoomTakenDuringPeriod(Date &start, Date &end, unsigned roomId)
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

Room Hotel::findOpenRoom(Date &start, Date &end, unsigned requiredBedCount)
{
    assert(roomsCount > 0);

    bool hasOpenRoom = false;
    unsigned minRoomId, minBedCount;

    for (unsigned i = 0; i < roomsCount; ++i)
    {
        unsigned currentRoomId = rooms[i].getRoomId();
        unsigned currentBedCount = rooms[i].getBedCount();
        if (!isRoomTakenDuringPeriod(start, end, currentRoomId) && currentBedCount >= requiredBedCount && (!hasOpenRoom || minBedCount > currentBedCount))
        {
            hasOpenRoom = true;
            minRoomId = currentRoomId;
            minBedCount = currentBedCount;
        }
    }

    if (!hasOpenRoom)
    {
        throw NoOpenRoomMatchingCriteriaFoundException();
    }

    Room r(minRoomId, minBedCount);
    return r;
}
