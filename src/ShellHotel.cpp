#include <cstring>
#include <fstream>
#include <assert.h>
#include <cstdio>

#include "ShellHotel.hpp"
#include "Exceptions.hpp"

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
    if (!hasRoomWithId(roomId))
    {
        std::cout << "Room with room number{" << roomId << "} doesn't exist.\n";
        return;
    }

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

void ShellHotel::listFreeRooms(Date &date)
{
    for (unsigned i = 0; i < roomsCount; ++i)
    {
        bool isFree = true;

        for (unsigned j = 0; isFree && j < reservationsCount; ++j)
        {
            if (isRoomTakenDuringPeriod(date, date, rooms[i].getRoomId()))
            {
                isFree = false;
            }
        }

        if (isFree)
        {
            std::cout << "Room {" << rooms[i].getRoomId() << "} is free.\n";
        }
    }
}

// void releaseRoom(unsigned roomId)
// {
// }

void ShellHotel::reservationInquiry(Date &periodStart, Date &periodEnd)
{
    unsigned reportFileNameLength = 22; // report-YYYY-MM-DD.txt is with length 21 and 1 terminating symbol
    const char *reportFormat = "report-%04d-%02d-%02d.txt";
    char *reportFileName = new char[reportFileNameLength];
    std::snprintf(reportFileName, reportFileNameLength, reportFormat, periodStart.getYear(), periodStart.getMonth(), periodStart.getDay());

    std::fstream reportFile;

    reportFile.open(reportFileName, std::ios::out | std::ios::trunc);

    assert(reportFile.is_open());

    reportFile << "Room Id,Days Used\n";

    for (unsigned i = 0; i < roomsCount; ++i)
    {
        unsigned daysUsed = 0;
        unsigned roomId = rooms[i].getRoomId();

        for (unsigned j = 0; j < reservationsCount; ++j)
        {
            if (roomId == reservations[j].getRoomId() && periodStart < reservations[j].getStart() && reservations[j].getEnd() < periodEnd)
            {
                daysUsed += reservations[j].reservationPeriodDays();
            }
        }

        if (daysUsed != 0)
        {
            reportFile << roomId << ',' << daysUsed << '\n';
        }
    }

    reportFile.close();
    delete[] reportFileName;
}

void ShellHotel::printOpenRoom(Date &start, Date &end, unsigned bedCount)
{
    try
    {
        Room r = findOpenRoom(start, end, bedCount);
        std::cout << "Found room " << r.getRoomId() << " that is free for the period [" << start << "] - [" << end << "] and has [" << r.getBedCount() << "] beds.\n";
    }
    catch(...)
    {
        std::cout << "No room during period [" << start << "] - [" << end << "] with " << bedCount << " numbers of bed could be found.\n";
    }
}

Date ShellHotel::inputDate()
{
    unsigned year, month, day;

    std::cin >> year >> month >> day;

    if (!Date::validDate(year, month, day))
    {
        throw DateInvalidException();
    }

    Date d(year, month, day);
    return d;
}
