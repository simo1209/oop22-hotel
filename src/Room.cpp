#include <iostream>
#include <fstream>
#include <assert.h>

#include "Room.hpp"

bool Room::validRoom(unsigned roomId, unsigned bedCount) {
    return roomId != 0 && bedCount != 0;
}

void Room::validateRoom() const
{
    assert(validRoom(roomId, bedCount));
}

Room::Room(unsigned roomId, unsigned bedCount) : roomId(roomId), bedCount(bedCount){
    validateRoom();
}

std::istream &operator>>(std::istream &is, Room &room)
{
    return (is >> room.roomId >> room.bedCount);
}

std::ostream &operator<<(std::ostream &os, Room const &room)
{
    return os << room.getRoomId() << ' ' << room.getBedCount();
}