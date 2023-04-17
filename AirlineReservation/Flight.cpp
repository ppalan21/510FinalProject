#include "Flight.h"
#include <ostream>

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

void Flight::set(unsigned int num, std::string src, std::string dst, unsigned int st, unsigned int dur, double price) {
	m_number = num;
	m_source = src;  
	m_destination = dst; 
	m_start_time = st; 
	m_duration = dur;  
	m_price = price;
}

std::ostream& operator<<(std::ostream& os, const Flight& flight) {
	os << "***\n";
	os << "Flight " << flight.m_number << " details:\n";
	os << flight.m_source << " --> " << flight.m_destination << "\n";
	os << "Start time: " << flight.m_start_time << " PST\n";
	os << "Duration: " << flight.m_duration << " minutes\n";
	os << "Price per seat: " << flight.m_price << " $\n";
	os << "***\n";
	return os;
}