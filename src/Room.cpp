#include <iostream>
#include <fstream>
#include <assert.h>

#include "Room.hpp"

void Room::validateRoom()
{
    assert(this->roomId != 0);
    assert(this->bedCount != 0);
}

void Room::write(std::fstream &bfs)
{
    validateRoom();
    bfs.seekp(0, std::ios_base::end);
    bfs.write((char const *)this, sizeof(Room));
}

void Room::read(std::fstream &bfs, std::streampos pos)
{
    bfs.seekg(pos);
    bfs.read((char *)this, sizeof(Room));
    validateRoom();
}

std::istream &operator>>(std::istream &is, Room &room)
{
    return (is >> room.roomId >> room.bedCount);
}

std::ostream &operator<<(std::ostream &os, Room const &room)
{
    return os << room.getRoomId() << ' ' << room.getBedCount() << '\n';
}