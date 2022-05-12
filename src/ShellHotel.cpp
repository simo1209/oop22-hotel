#include <cstring>
#include <fstream>
#include <assert.h>

#include "ShellHotel.hpp"

ShellHotel::ShellHotel(char const *roomsFileName, char const *reservationsFileName)
{
    setRoomsFileName(roomsFileName);
    setReservationsFileName(reservationsFileName);

    this->roomsFile.open(this->roomsFileName, std::ios::binary | std::ios::in | std::ios::out);
    this->reservationsFile.open(this->reservationsFileName, std::ios::in | std::ios::out);

    loadRooms();
    loadReservations();
}

ShellHotel::~ShellHotel()
{
    delete[] roomsFileName;
    delete[] reservationsFileName;

    delete[] rooms;
    delete[] reservations;

    this->roomsFile.close();
    this->reservationsFile.close();
}

void ShellHotel::setRoomsFileName(char const *roomsFileName)
{
    this->roomsFileName = new char[MAX_FILE_NAME];
    strncpy(this->roomsFileName, roomsFileName, MAX_FILE_NAME);
    this->roomsFileName[MAX_FILE_NAME - 1] = '\0';
}

void ShellHotel::setReservationsFileName(char const *reservationsFileName)
{
    this->reservationsFileName = new char[MAX_FILE_NAME];
    strncpy(this->reservationsFileName, reservationsFileName, MAX_FILE_NAME);
    this->reservationsFileName[MAX_FILE_NAME - 1] = '\0';
}

void ShellHotel::loadRooms()
{
    assert(roomsFile.is_open());
    roomsFile.seekg(0, std::ios::end);
    std::streampos end = roomsFile.tellg();

    rooms = new Room[end / sizeof(Room)];

    assert(end != 0);

    roomsFile.seekg(0);

    for (roomsCount = 0; !roomsFile.eof() && roomsCount < end / sizeof(Room); roomsCount++)
    {
        roomsFile.read((char *)(rooms + roomsCount), sizeof(Room));
    }
}

void ShellHotel::loadReservations()
{
    assert(reservationsFile.is_open());

    reservationsFile >> reservationsCount;

    reservations = new Reservation[reservationsCount];

    for (size_t i = 0; !reservationsFile.eof() && i < reservationsCount; i++)
    {
        reservationsFile >> reservations[i];
    }
}

void ShellHotel::createReservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservatorName)
{
    if (isRoomTakenDuringPeriod(start, end, roomId))
    {
        std::cout << "Room is taken during supplied period.\n";
        return;
    }

    Reservation reservation(start, end, roomId, note, reservatorName);

    reservationsFile.clear();
    reservationsFile.seekp(0);

    reservationsFile << ++reservationsCount;

    reservationsFile.seekp(0, std::ios::end);

    reservationsFile << reservation << '\n';

    reservationsFile.flush();
    reservationsFile.clear();

    delete[] reservations;

    loadReservations();
}

// void listFreeRooms(Date &date)
// {
// }

// void releaseRoom(unsigned roomId)
// {
// }

// void reservationInquiry(Date &start, Date &end)
// {
// }

// Room findOpenRoom(Date start, Date end, unsigned bedCount)
// {
// }
