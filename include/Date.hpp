#include <istream>
#include <ostream>

#ifndef __DATE_HPP
#define __DATE_HPP

/**
 * @brief Клас за дата.
 *
 * Използва се за да пази година, месец и час на дадена дата.
 */
class Date
{
private:

    /**
     * @brief Година на датата.
     */
    unsigned year;

    /**
     * @brief Месец на датата.
     */
    unsigned month;

    /**
     * @brief Ден на датата.
     *
     */
    unsigned day;

    /**
     * @brief Статична член функция за проверка дали година е високосна.
     *
     * @param year годината, която се проверява за високосност
     * @return true ако годината е високосна
     */
    static bool isLeap(unsigned year);

public:
    /**
     * @brief Конструктор за нов обект за дата.
     *
     * @param year годината на датата
     * @param month месеца на датата
     * @param day деня на датата
     */
    Date(unsigned year = 2022, unsigned month = 5, unsigned day = 8);

    /**
     * @brief Селектор за годината на датата.
     * 
     * @return unsigned годината на датата
     */
    unsigned getYear() const { return year; }

    /**
     * @brief Селектор за месеца на датата.
     * 
     * @return unsigned месеца на датата
     */
    unsigned getMonth() const { return month; }

    /**
     * @brief Селектор за деня на датата.
     * 
     * @return unsigned деня на датата
     */
    unsigned getDay() const { return day; }

    /**
     * @brief Статична член функция за проверка дали подадените година, месец и ден образуват валидна дата.
     *
     * @param year годината на датата, която се проверява за валидност
     * @param month месеца на датата, която се проверява за валидност
     * @param day деня на датата, която се проверява за валидност
     * @return true ако годината, месеца и деня образуват валидна дата.
     */
    static bool validDate(unsigned year, unsigned month, unsigned day);

    /**
     * @brief Оператор за строго по-малко сравняване на дати.
     *
     * @param left датата от лявата страна на сравняването
     * @param right датата от дясната страна на сравняването
     * @return true ако датата от лявата страна е строго преди датата от дясната страна
     */
    friend bool operator<(Date const &left, Date const &right);

    /**
     * @brief Оператор за строго по-голямо сравняване на дати.
     *
     * @param left датата от лявата страна на сравняването
     * @param right датата от дясната страна на сравняването
     * @return true ако датата от лявата страна е строго след датата от дясната страна
     */
    friend bool operator>(Date const &left, Date const &right) { return right < left; };

    /**
     * @brief Оператор за нестрого по-малко сравняване на дати.
     *
     * @param left датата от лявата страна на сравняването
     * @param right датата от дясната страна на сравняването
     * @return true ако датата от лявата страна е преди или съвпада с датата от дясната страна
     */
    friend bool operator<=(Date const &left, Date const &right) { return !(left > right); };

    /**
     * @brief Оператор за строго по-малко сравняване на дати.
     *
     * @param left датата от лявата страна на сравняването
     * @param right датата от дясната страна на сравняването
     * @return true ако датата от лявата страна е след или съвпада с датата от дясната страна
     */
    friend bool operator>=(Date const &left, Date const &right) { return !(left < right); };

    /**
     * @brief Оператор за форматиран вход на дата.
     *
     * Прочита дата от поток с форматиран вход.
     *
     * @param is потока, от който се въвежда датата
     * @param date датата за въвеждане
     * @return std::istream& потока, ог който е въведена датата
     */
    friend std::istream &operator>>(std::istream &is, Date &date);
};

/**
 * @brief Оператор за форматиран изход на дата.
 *
 * Извежда датата на потока, във формат "YYYY MM DD".
 *
 * @param os потока, на който се извежда датата
 * @param date датата за извеждане
 * @return std::ostream& потока, на който е изведена датата
 */
std::ostream &operator<<(std::ostream &os, Date const &date);

#endif