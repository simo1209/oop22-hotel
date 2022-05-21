#include <fstream>

#include "ShellHotel.hpp"

int main()
{

    ShellHotel hotel("rooms.bin", "reservations.txt");

    Date date;
    std::cout << "Supply date for which to list all free rooms (date is in format YYYY MM DD):\n";
    std::cout << "Date: \n";

    try
    {
        date = hotel.inputDate();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    hotel.listFreeRooms(date);

    return 0;
}
