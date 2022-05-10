#include <iostream>
#include <fstream>
#include <assert.h>

#include "Room.hpp"

bool Room::validRoom(unsigned roomId, unsigned bedCount)
{
    return roomId != 0 && bedCount != 0;
}

std::istream &operator>>(std::istream &is, Room &room)
{
    is >> room.roomId >> room.bedCount;
    assert(room.validRoom(room.roomId, room.bedCount));
    return is;
}

std::ostream &operator<<(std::ostream &os, Room const &room)
{
    return os << room.getRoomId() << ' ' << room.getBedCount();
}