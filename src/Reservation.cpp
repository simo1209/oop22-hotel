#include <cstring>
#include <assert.h>

#include "Reservation.hpp"

Reservation::Reservation()
{
    setNote("");
    setReservatorName("");
}

Reservation::Reservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservatorName) : start(start), end(end), roomId(roomId)
{
    assert(start < end);
    assert(roomId != 0);
    setNote(note);
    setReservatorName(reservatorName);
}

Reservation::~Reservation()
{
    delete[] note;
    delete[] reservatorName;
}

void Reservation::setNote(char const *note)
{
    this->note = new char[MAX_NOTE_LEN];
    strncpy(this->note, note, MAX_NOTE_LEN);
    this->note[MAX_NOTE_LEN - 1] = '\0';
}

void Reservation::setReservatorName(char const *reservatorName)
{
    this->reservatorName = new char[MAX_RESERVATOR_NAME_LEN];
    strncpy(this->reservatorName, reservatorName, MAX_RESERVATOR_NAME_LEN);
    this->reservatorName[MAX_RESERVATOR_NAME_LEN - 1] = '\0';
}

unsigned Reservation::reservationPeriodDays(){
    // oversimplified days calculation
    return (end.getYear() - start.getYear()) * 365 + (end.getMonth() - start.getMonth()) * 30 + end.getDay() - start.getDay();
}

std::istream &operator>>(std::istream &is, Reservation &reservation)
{
    return (is >> reservation.start >> reservation.end >> reservation.roomId).ignore().get(reservation.note, MAX_NOTE_LEN, ' ').ignore().get(reservation.reservatorName, MAX_RESERVATOR_NAME_LEN, '\n');
}

std::ostream &operator<<(std::ostream &os, Reservation const &reservation)
{
    return os << reservation.getStart() << ' ' << reservation.getEnd() << ' ' << reservation.getRoomId() << ' ' << reservation.getNote() << ' ' << reservation.getReservatorName();
}
