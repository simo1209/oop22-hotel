#include "Room.hpp"
#include "Date.hpp"
#include "Reservation.hpp"

#ifndef __HOTEL_HPP
#define __HOTEL_HPP

/**
 * @brief Абстрактен клас за работа с Хотел.
 * 
 * Позволява абстракция от имплементационните детаили на ShellHotel(клас за работа с хотел в диалогов режим).
 * 
 */
class Hotel
{
protected:

    /**
     * @brief Броя на стаите в хотела.
     */
    size_t roomsCount;

    /**
     * @brief Колекция за стаите в хотела.
     */
    Room *rooms;

    /**
     * @brief Броя на резервациите в хотела.
     */
    size_t reservationsCount;

    /**
     * @brief Колекция за резервациите в хотела.
     */
    Reservation *reservations;

    /**
     * @brief Член-функция за проверка, дали даден номер на стая съотвества на някоя стая в хотела.
     *
     * @param roomId номер на стаята, за която да се провери че съществува
     * @return true ако в хотела съществува стая с номер roomId
     */
    bool hasRoomWithId(unsigned roomId);

    /**
     * @brief Член функция за проверка зали стая е заета в даден период.
     * 
     * @param start начало на периода
     * @param end край на периода
     * @param roomId номер на стая
     * @return true ако стаята с номер roomId е свободна за периода start end
     */
    bool isRoomTakenDuringPeriod(Date &start, Date &end, unsigned roomId);

    /**
     * @brief Член-функция за намиране на свободна стая в даден период.
     * 
     * При наличие на повече свободни стаи се предпочита такива с по-малко на брой легла.
     * 
     * @param start начало на периода
     * @param end края на периода
     * @param bedCount минимален брой легла на стаята, която се търси
     * @return Room стая с поне bedCount легла, която е свободна за периода start end
     * @throws NoOpenRoomMatchingCriteriaFoundException Не е намерена свободна стая в дадения период, която да има поне bedCount на брой легла.
     */
    Room findOpenRoom(Date &start, Date &end, unsigned bedCount);

    /**
     * @brief Виртуална член-функция за зареждане на стаите в колекцията за стаи.
     */
    virtual void loadRooms() = 0;

    /**
     * @brief Виртуална член-функция за зареждане на резервациите в колекцията за резервации
     */
    virtual void loadReservations() = 0;

public:

    /**
     * @brief Селектор за броя на стаи в хотела.
     * 
     * @return size_t броя на стаи в хотела
     */
    size_t getRoomsCount() { return roomsCount; }

    /**
     * @brief Селектор за броя на резервации в хотела.
     * 
     * @return size_t броя на резервации в хотела
     */
    size_t getReservationsCount() { return reservationsCount; }

    /**
     * @brief Виртуална член-функция за регистриране на гост.
     * 
     * Регистриране на гости в стая с даден номер за въведен период, може да се въвежда и бележка за резервацията и се добавя името на госта (само едно име на стая).
     * 
     * @param start начало на периода на резервацията
     * @param end край на периода на резервацията
     * @param roomId номер на стаята на резервацията
     * @param note бележка за резервацията
     * @param reservatorName име на госта, направил резервацията
     */
    virtual void createReservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservatorName) = 0;

    /**
     * @brief Виртуална член-функция за списък на свободни стаи.
     * 
     * Извежда списък на свободните стаи за дадена дата.
     * 
     * @param date дата, на която всички изведени стаи са свободни
     */
    virtual void listFreeRooms(Date &date) = 0;
    // virtual void releaseRoom(unsigned roomId) = 0;

    /**
     * @brief Виртуална член-функция за справка на заетост.
     * 
     * Извежда справка за използването на хотела в даден период.
     * 
     * @param periodStart начало на периода на справката
     * @param periodEnd край на периода на справката
     */
    virtual void reservationInquiry(Date &periodStart, Date &periodEnd) = 0;

    /**
     * @brief Виртуална член-функция за принтиране на свободна стая в даден период с минимален брой легла.
     * 
     * При наличие на повече свободни стаи се предпочита такива с по-малко на брой легла.
     * 
     * @param start начало на периода
     * @param end край на периода
     * @param bedCount минимален брой легла на принтираната стая
     */
    virtual void printOpenRoom(Date &start, Date &end, unsigned bedCount) = 0;
};

#endif