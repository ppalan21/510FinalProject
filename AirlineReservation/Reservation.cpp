#include "Reservation.h"
#include <ostream>
#include <format>

void add_reservationlist_header(std::ostream& os) {
	os	<< std::format("{:<25}", "ReservationNumber")
		<< std::format("{:<25}", "PassengerName")
		<< std::format("{:<25}", "NumberOfPassengers")
		<< std::format("{:<25}", "Seats");
	os << "\n";
}

Reservation::Reservation()
	: m_number(0), m_name("---"), m_numpassengers(0) {

}

Reservation::Reservation(unsigned int num, std::string name, unsigned int numpassengers, std::list<std::pair<char, unsigned int>>& seats)
	: m_number(num), m_name(name), m_numpassengers(numpassengers), m_seats(seats) {

}

unsigned int Reservation::getnumber() const {
	return m_number;
}

std::string Reservation::getname() const {
	return m_name;
}

unsigned int Reservation::getnumpassengers() const {
	return m_numpassengers;
}

std::list<std::pair<char, unsigned int>> Reservation::getseats() const {
	return m_seats;
}

void Reservation::setnumber(unsigned int num) {
	m_number = num;
}

void Reservation::setname(std::string name) {
	m_name = name;
}

void Reservation::setnumpassengers(unsigned int numpassengers) {
	m_numpassengers = numpassengers;
}

void Reservation::setseats(std::list<std::pair<char, unsigned int>>& seats) {
	m_seats = seats;
}

bool Reservation::operator== (Reservation& other) {
	if (m_number == other.m_number &&
		m_name == other.m_name &&
		m_numpassengers == other.m_numpassengers &&
		m_seats == other.m_seats) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
	os	<< std::format("{:<25}", reservation.m_number)
		<< std::format("{:<25}", reservation.m_name)
		<< std::format("{:<25}", reservation.m_numpassengers);
	for (const auto& item : reservation.m_seats) {
		os << item.first << item.second << " ";
	}
	os << "\n";
	return os;
}