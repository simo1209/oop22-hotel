#include <istream>
#include <fstream>
#include <iostream>

#ifndef __ROOM_HPP
#define __ROOM_HPP

class Room
{
    unsigned roomId;
    unsigned bedCount;

    static bool validRoom(unsigned roomId, unsigned bedCount);

    void validateRoom() const;

public:
    Room(unsigned roomId = 0, unsigned bedCount = 0);

    unsigned getRoomId() const { return roomId; }
    unsigned getBedCount() const { return bedCount; }

    friend std::istream &operator>>(std::istream &is, Room &room);
};

std::ostream &operator<<(std::ostream &os, Room const &room);

#endif