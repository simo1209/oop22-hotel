#include <istream>
#include <fstream>
#include <iostream>

#ifndef __ROOM_HPP
#define __ROOM_HPP

class Room
{
    unsigned roomId;
    unsigned bedCount;

public:
    unsigned getRoomId() const { return roomId; }
    unsigned getBedCount() const { return bedCount; }

    friend std::istream &operator>>(std::istream &is, Room &room);

    void read(std::fstream &bfs, std::streampos pos);

    // Write method for populating the rooms.bin file for testing purposes
    void write(std::fstream &bfs) const;
};

std::ostream &operator<<(std::ostream &os, Room const &room);

#endif