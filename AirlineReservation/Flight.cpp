#include "Flight.h"
#include <ostream>
#include <iomanip>

Flight::Flight()
	: m_number(0), m_source("---"), m_destination("---"), m_start_time(0), m_duration(0), m_price(0) {

}

Flight::Flight(unsigned int num, std::string src, std::string dst, unsigned int st, unsigned int dur, double price)
	: m_number(num), m_source(src), m_destination(dst), m_start_time(st), m_duration(dur), m_price(price) {

}

unsigned int Flight::getnumber() const {
	return m_number;
}

std::string Flight::getsource() const {
	return m_source;
}

std::string Flight::getdestination() const {
	return m_destination;
}

unsigned int Flight::getstarttime() const {
	return m_start_time;
}

unsigned int Flight::getduration() const {
	return m_duration;
}

double Flight::getprice() const {
	return m_price;
}

void Flight::setnumber(unsigned int num) {
	m_number = num;
}

void Flight::setsource(std::string src) {
	m_source = src;
}

void Flight::setdestination(std::string dst) {
	m_destination = dst;
}

void Flight::setstarttime(unsigned int st) {
	m_start_time = st;
}

void Flight::setduration(unsigned int dur) {
	m_duration = dur;
}

void Flight::setprice(double price) {
	m_price = price;
}

bool Flight::operator== (Flight& other) {
	if (m_number == other.m_number &&
		m_source == other.m_source &&
		m_destination == other.m_destination &&
		m_start_time == other.m_start_time &&
		m_duration == other.m_duration &&
		m_price == other.m_price) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Flight& flight) {
	os << flight.m_number;
	os << std::setw(15) << flight.m_source;
	os << std::setw(15) << flight.m_destination;
	os << std::setw(15) << flight.m_start_time;
	os << std::setw(15) << flight.m_duration;
	os << std::setw(15) << flight.m_price;
	return os;
}