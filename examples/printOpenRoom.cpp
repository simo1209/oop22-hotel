#include <fstream>

#include "ShellHotel.hpp"

int main()
{

    ShellHotel hotel("rooms.bin", "reservations.txt");

    Date start, end;
    std::cout << "Supply start date and end date for your reservation (date is in format YYYY MM DD):\n";
    std::cout << "Start date: \n";

    try
    {
        start = hotel.inputDate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    std::cout << "End date: \n";
    try
    {
        end = hotel.inputDate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    unsigned desiredBedCount;
    std::cout << "Supply number of beds for the room:\n";
    std::cin >> desiredBedCount;


    hotel.printOpenRoom(start, end, desiredBedCount);
    
    return 0;
}
