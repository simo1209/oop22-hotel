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
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    std::cout << "End date: \n";
    try
    {
        end = hotel.inputDate();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    unsigned roomId;
    std::cout << "Enter the number of the room to be resserved:\n";
    std::cin >> roomId;

    char note[MAX_NOTE_LEN];
    std::cout << "Enter note for the reservation:\n";
    std::cin >> note;


    char reservatorName[MAX_RESERVATOR_NAME_LEN];
    std::cout << "Enter the name of the guest for the reservation:\n";
    std::cin >> reservatorName;


    hotel.createReservation(start, end, roomId, note, reservatorName);

    return 0;
}
