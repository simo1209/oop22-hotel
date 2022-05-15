#include "Date.hpp"
#include "Room.hpp"

#ifndef __RESERVATION_HPP
#define __RESERVATION_HPP

const size_t MAX_NOTE_LEN = 100;
const size_t MAX_RESERVATOR_NAME_LEN = 100;

/**
 * @brief Клас за резервация.
 */
class Reservation
{
private:
    /**
     * @brief начало на резервазията
     */
    Date start;

    /**
     * @brief край на резервацията
     */
    Date end;

    /**
     * @brief номер на резервираната стая
     */
    unsigned roomId;

    /**
     * @brief бележка към резервацията
     */
    char *note;

    /**
     * @brief име на госта, направил резервацията
     */
    char *reservatorName;

    /**
     * @brief Член-функция за проверка за валидност на резервация.
     *
     */
    void reservationValid();

    /**
     * @brief Мутатор на текстовия низ за бележката към резервацията
     *
     * @param note
     */
    void setNote(char const *note);

    /**
     * @brief Мутатор на текстовия низ за името на госта, направил резервацията
     *
     * @param reservatorName
     */
    void setReservatorName(char const *reservatorName);

public:
    /**
     * @brief Конструктор по подразбиране за резервация
     */
    Reservation();

    /**
     * @brief Конструктор за копиране на обект от тип резервация
     *
     * @param other обект, който да копира
     */
    Reservation(Reservation const &other);

    /**
     * @brief Оператор за копиране на обект от тип резервация
     *
     * @param other обект, който да копира
     * @return Reservation& копираната резервация
     */
    Reservation &operator=(Reservation const &other);

    /**
     * @brief Конструктор за нов обект от тип резервация
     *
     * @param start начало на резервацията
     * @param end край на резервацията
     * @param roomId номер на резервираната стая
     * @param note бележка към резервацията
     * @param reservatorName име на госта, резервирал стаята
     */
    Reservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservatorName);

    /**
     * @brief Деструктор за обект от тип резервация
     */
    ~Reservation();

    /**
     * @brief Селектор за началото на резервацията
     *
     * @return Date начало на резервацията
     */
    Date getStart() const { return start; }

    /**
     * @brief Селектор за края на резервацията
     *
     * @return Date края на резервацията
     */
    Date getEnd() const { return end; }

    /**
     * @brief Селектор за номера на стаята на резервацията
     *
     * @return unsigned номер на стаята на резервацията
     */
    unsigned getRoomId() const { return roomId; }

    /**
     * @brief Селектор за бележката към резервацията
     *
     * @return char const* бележка към резервацията
     */
    char const *getNote() const { return note; }

    /**
     * @brief Селектор за името на госта, направил резервацията
     *
     * @return char const* името на госта, направил резервацията
     */
    char const *getReservatorName() const { return reservatorName; }

    /**
     * @brief Селектор за продължителноста на резервацията
     *
     * @return unsigned брой дни за които е направена резервацията
     */
    unsigned reservationPeriodDays();

    /**
     * @brief Оператор за форматиран вход на резервация.
     *
     * Въвежда резервация от потока.
     *
     * @param os потока, от който се въвежда резервацията
     * @param reservation резервацията за извеждане
     * @return std::ostream& потока, от който е въведена резервацията
     */
    friend std::istream &operator>>(std::istream &is, Reservation &reservation);
};

/**
 * @brief Оператор за форматиран изход на резервация.
 *
 * Извежда резервацията на потока, във формат "start end roomId note reservatorName".
 *
 * @param os потока, на който се извежда резервацията
 * @param reservation резервацията за извеждане
 * @return std::ostream& потока, на който е изведена резервацията
 */
std::ostream &operator<<(std::ostream &os, Reservation const &reservation);

#endif