#include <iostream>
#include <fstream>

#include "Room.hpp"

void Room::write(std::fstream &bfs) const
{
    bfs.seekp(0, std::ios_base::end);
    bfs.write((char const *)this, sizeof(Room));
}

void Room::read(std::fstream &bfs, std::streampos pos)
{
    bfs.seekg(pos);
    bfs.read((char *)this, sizeof(Room));
}

std::istream &operator>>(std::istream &is, Room &room)
{
    return (is >> room.roomId >> room.bedCount);
}

std::ostream &operator<<(std::ostream &os, Room const &room)
{
    return os << room.getRoomId() << ' ' << room.getBedCount() << '\n';
}