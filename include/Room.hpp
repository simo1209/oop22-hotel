#include <istream>
#include <fstream>
#include <iostream>

#ifndef __ROOM_HPP
#define __ROOM_HPP

/**
 * @brief Клас за стая.
 */
class Room
{
    /**
     * @brief номер на стаята
     */
    unsigned roomId;

    /**
     * @brief брой легла в стаята
     */
    unsigned bedCount;

    /**
     * @brief статична член-функция за проверка на валидност на стая
     *
     * @param roomId номер на стаята
     * @param bedCount брой легла в стаята
     * @return true ако номера на стаята не е 0 и има поне 1 легло в стаята
     */
    static bool validRoom(unsigned roomId, unsigned bedCount);

public:
    /**
     * @brief Конструктор за нов обект от тип стая
     *
     * @param roomId номер на стаята
     * @param bedCount брой легла в стята
     */
    Room(unsigned roomId = 0, unsigned bedCount = 0) : roomId(roomId), bedCount(bedCount){};

    /**
     * @brief Селектор за номер на стаята
     *
     * @return unsigned номер на стаята
     */
    unsigned getRoomId() const { return roomId; }

    /**
     * @brief Селектор за броя легла в стаята
     *
     * @return unsigned брой легла в стаята
     */
    unsigned getBedCount() const { return bedCount; }

    /**
     * @brief Оператор за форматиран вход на стая.
     *
     * Въвежда стаята от потока.
     *
     * @param is потока, от който се въвежда стаята
     * @param room стаята за въвеждане
     * @return std::istream& потока, от който е въведена стаята
     */
    friend std::istream &operator>>(std::istream &is, Room &room);
};

/**
 * @brief Оператор за форматиран изход на стая.
 *
 * Извежда стаята на потока, във формат "roomId bedCount".
 *
 * @param os потока, на който се извежда стаята
 * @param room стаята за извеждане
 * @return std::ostream& потока, на който е изведена стаята
 */
std::ostream &operator<<(std::ostream &os, Room const &room);

#endif