#include <fstream>

#include "Hotel.hpp"

#ifndef __SHELL_HOTEL_HPP
#define __SHELL_HOTEL_HPP

const size_t MAX_FILE_NAME = 100;

class ShellHotel : public Hotel
{
    char *roomsFileName;
    char *reservationsFileName;

    std::fstream roomsFile;
    std::fstream reservationsFile;

    void setRoomsFileName(char const *roomsFileName);
    void setReservationsFileName(char const *reservationsFileName);

    void loadRooms();
    void loadReservations();

public:
    ShellHotel(char const *roomsFileName, char const *reservationsFileName);
    ~ShellHotel();

    void createReservation(Date &start, Date &end, unsigned roomId, char const * note, char const *reservatorName = "");
    // void listFreeRooms(Date &date);
    // void releaseRoom(unsigned roomId);
    // void reservationInquiry(Date &start, Date &end);
    // Room findOpenRoom(Date start, Date end, unsigned bedCount);
};

#endif