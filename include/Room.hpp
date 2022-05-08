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

    friend std::istream& operator>>(std::istream &is, Room & room);

    void write(std::fstream &bfs) const;
    void read(std::fstream &bfs, std::streampos pos);
};

std::ostream& operator<<(std::ostream &os, Room const &room);

#endif