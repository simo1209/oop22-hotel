#include <cstring>

#include "Reservation.hpp"

Reservation::Reservation(){
    setNote("");
    setReservator("");
}

Reservation::Reservation(Date &start, Date &end, unsigned roomId, char const *note, char const *reservator) : start(start), end(end), roomId(roomId)
{
    setNote(note);
    setReservator(reservator);
}

Reservation::~Reservation()
{
    delete[] note;
    delete[] reservator;
}

void Reservation::setNote(char const *note)
{
    this->note = new char[MAX_NOTE_LEN];
    strncpy(this->note, note, MAX_NOTE_LEN);
    this->note[MAX_NOTE_LEN - 1] = '\0';
}

void Reservation::setReservator(char const *reservator)
{
    this->reservator = new char[MAX_RESERVATOR_LEN];
    strncpy(this->reservator, reservator, MAX_RESERVATOR_LEN);
    this->reservator[MAX_RESERVATOR_LEN - 1] = '\0';
}

std::istream &operator>>(std::istream &is, Reservation &reservation)
{
    return (is >> reservation.start >> reservation.end >> reservation.roomId).ignore().get(reservation.note, MAX_NOTE_LEN).get(reservation.reservator, MAX_RESERVATOR_LEN);
}

std::ostream &operator<<(std::ostream &os, Reservation const &reservation)
{
    return os << reservation.getStart() << ' ' << reservation.getEnd() << ' ' << reservation.getRoomId() << ' ' << reservation.getNote() << ' ' << reservation.getReservator();
}
