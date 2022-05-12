#include "Date.hpp"
#include "Room.hpp"

#ifndef __RESERVATION_HPP
#define __RESERVATION_HPP

const size_t MAX_NOTE_LEN = 100;
const size_t MAX_RESERVATOR_NAME_LEN = 100;

class Reservation
{
private:
    Date start;
    Date end;
    unsigned roomId;
    char *note;
    char *reservatorName;

    void setNote(char const *note);
    void setReservatorName(char const *reservatorName);

public:
    Reservation();
    Reservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservatorName);
    ~Reservation();

    Date getStart() const { return start; }
    Date getEnd() const { return end; }
    unsigned getRoomId() const { return roomId; }
    char const *getNote() const { return note; }
    char const *getReservatorName() const { return reservatorName; }

    unsigned reservationPeriodDays();

    friend std::istream &operator>>(std::istream &is, Reservation &reservation);
};

std::ostream &operator<<(std::ostream &os, Reservation const &reservation);

#endif