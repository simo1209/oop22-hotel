#include <fstream>

#include "Hotel.hpp"

#ifndef __SHELL_HOTEL_HPP
#define __SHELL_HOTEL_HPP

const size_t MAX_FILE_NAME = 100;

/**
 * @brief Клас за работа с хотел в диалогов режим.
 */
class ShellHotel : public Hotel
{

    /**
     * @brief Текстов низ за името на файла за съхранение на стаите.
     */
    char *roomsFileName;

    /**
     * @brief Текстов низ за името на файла за съхранение на резервациите.
     */
    char *reservationsFileName;

    /**
     * @brief Поток от файл за съхранение на стаите в хотела.
     */
    std::fstream roomsFile;

    /**
     * @brief Поток от файл за съхранение на резервациите в хотела.
     */
    std::fstream reservationsFile;

    /**
     * @brief Мутатор на името на файла за съхранение на стаите.
     *
     * @param roomsFileName текстов низ за новото име на файла за съхранение на стаите
     */
    void setRoomsFileName(char const *roomsFileName);

    /**
     * @brief Мутатор на името на файла за съхранение на резервациите.
     *
     * @param reservationsFileName текстов низ за новото име на файла за съхранение на резервациите
     */
    void setReservationsFileName(char const *reservationsFileName);

    /**
     * @brief Член-функция за зареждане на стаите от файла с име roomsFileName в колекцията за стаи.
     */
    void loadRooms();

    /**
     * @brief Член-функция за зареждане на резервациите от файла с име reservationsFile в колекцията за резервации.
     */
    void loadReservations();

public:
    /**
     * @brief Конструктор за нов обект от тип ShellHotel
     *
     * @param roomsFileName текстов низ за името на файла за съхранение на стаите
     * @param reservationsFileName текстов низ за името на файла за съхранение на резервациите
     */
    ShellHotel(char const *roomsFileName, char const *reservationsFileName);

    /**
     * @brief Деструктор за обект от тип ShellHotel
     */
    ~ShellHotel();

    /**
     * @brief Член-функция за регистриране на гост.
     *
     * Регистриране на гости в стая с даден номер за въведен период, може да се въвежда и бележка за резервацията и се добавя името на госта (само едно име на стая). Създава нов обект от тип Reservation и го записва във файла с резервации.
     *
     * @param start начало на периода на резервацията
     * @param end край на периода на резервацията
     * @param roomId номер на стаята на резервацията
     * @param note бележка за резервацията
     * @param reservatorName име на госта, направил резервацията
     */
    void createReservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservatorName = "<CLOSED>");

    /**
     * @brief Член-функция за списък на свободни стаи.
     *
     * Извежда списък на свободните стаи за дадена дата на потока за стандартен изход.
     *
     * @param date дата, на която всички изведени стаи са свободни
     */
    void listFreeRooms(Date &date);
    // void releaseRoom(unsigned roomId);

    /**
     * @brief Член-функция за справка на заетост.
     *
     * Извежда справка за използването на стаи в даден период и я записва в текстов файл с име report-YYYY-MM-DD.txt, където YYYY-MM-DD е началната дата на периода. 
     * Извежда се списък, в който за всяка стая, използвана в дадения период, се извежда и броя на дните, в които е била използвана.
     *
     * @param periodStart начало на периода на справката
     * @param periodEnd край на периода на справката
     */
    void reservationInquiry(Date &periodStart, Date &periodEnd);

    /**
     * @brief Член-функция за принтиране на свободна стая в даден период с минимален брой легла.
     * 
     * При наличие на повече свободни стаи се предпочита такива с по-малко на брой легла.
     * 
     * @param start начало на периода
     * @param end край на периода
     * @param bedCount минимален брой легла на принтираната стая
     */
    void printOpenRoom(Date &start, Date &end, unsigned bedCount = 1);

    /**
     * @brief Член-функция за въвеждане на дата от потока за стандартен вход.
     * 
     * @return Date въведаната от потребителя дата
     * @throws DateInvalidException ако потребителят въведе несъществуваща датал Пр: 2022 02 30
     */
    Date inputDate();
};

#endif