#include "Flight.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <format>

Flight::Flight()
	: m_number(0), m_source("---"), m_destination("---"), m_start_time(0), m_duration(0), m_price(0) {

}

Flight::Flight(unsigned int num, std::string src, std::string dst, unsigned int st, unsigned int dur, double price)
	: m_number(num), m_source(src), m_destination(dst), m_start_time(st), m_duration(dur), m_price(price) {
	std::string filepath = "FlightDatabase\\Flight" + std::to_string(m_number) + ".txt";
	std::ifstream reslistfile(filepath);
	if (reslistfile.is_open()) {
		std::string mytext;
		int currentline = -1;
		while (std::getline(reslistfile, mytext)) {
			currentline++;
			if (currentline == 0) continue;
			std::stringstream ss;
			ss << mytext;
			unsigned int num, numpassengers;
			std::string name;
			std::list<std::pair<char, unsigned int>> seats;
			ss >> num >> name >> numpassengers;
			for (unsigned int i = 0; i < numpassengers; i++) {
				char column;
				unsigned int row;
				ss >> column >> row;
				seats.push_back(std::make_pair(column, row));
			}
			if (!ss) {
				std::cout << "Reservation details for row " << currentline << " of Flight " << m_number << " not parsed correctly\n";
				continue;
			}
			Reservation reservation(num, name, numpassengers, seats);
			m_reservationlist[num] = reservation;
		}
		reslistfile.close();
	}
	else {
		std::ofstream reslistfile(filepath);
		std::stringstream(ss);
		add_reservationlist_header(ss);
		reslistfile << ss.str();
		reslistfile.close();
	}
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

Reservation Flight::getreservation(unsigned int num) const {
	return m_reservationlist.at(num);
}

bool Flight::findreservation(unsigned int num) const {
	if (m_reservationlist.find(num) != m_reservationlist.end()) return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Flight& flight) {
	os << std::format("{:<25}", flight.m_number)
		<< std::format("{:<25}", flight.m_source)
		<< std::format("{:<25}", flight.m_destination)
		<< std::format("{:<25}", flight.m_start_time)
		<< std::format("{:<25}", flight.m_duration)
		<< std::format("{:<25}", flight.m_price);
	os << "\n";
	return os;
}

Flight::~Flight() {
	std::string filepath = "FlightDatabase\\Flight" + std::to_string(m_number) + ".txt";
	std::ofstream reslistfile(filepath);
	std::stringstream ss;
	add_reservationlist_header(ss);
	reslistfile << ss.str();
	for (auto& item : m_reservationlist) {
		std::stringstream ss;
		ss << item.second;
		reslistfile << ss.str();
	}
	reslistfile.close();
}