#include "Flight.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <format>

void add_reservationlist_header(std::ostream& os) {
	os << std::format("{:<25}", "ReservationNumber")
		<< std::format("{:<25}", "PassengerName")
		<< std::format("{:<25}", "NumberOfPassengers")
		<< std::format("{:<25}", "Seats");
	os << "\n";
}

Flight::Flight()
	: m_number(0), m_source("---"), m_destination("---"), m_start_time(0), m_duration(0), m_price(0) {

}

Flight::Flight(unsigned int num, std::string src, std::string dst, unsigned int st, unsigned int dur, double price)
	: m_number(num), m_source(src), m_destination(dst), m_start_time(st), m_duration(dur), m_price(price) {
	// function of the constructor is to read reservation info for each flight and initialize reservation instances
	std::string filepath = "FlightDatabase\\Flight" + std::to_string(m_number) + ".txt";
	std::ifstream reslistfile(filepath);
	// if file Flight<flight_number>.txt exists, then open it
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
	// if Flight<flight_number>.txt does not exist, create one with header file
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

Reservation& Flight::getreservation(unsigned int num) {
	return m_reservationlist.at(num);
}

bool Flight::findreservation(unsigned int num) const {
	if (m_reservationlist.find(num) != m_reservationlist.end()) return true;
	return false;
}

void Flight::cancelreservation(unsigned int num) {
	m_reservationlist.erase(num);
	std::cout << "Thank you. Your reservation (number " << num << ") has been cancelled\n";
}

unsigned int Flight::makereservation() {
	// get details for a new reservation
	std::cout << "\nPlease enter the following details:\n";
	std::string name = "---";
	std::cout << "Customer Name (Please enter in camel case format - Capitalize both first and last names and no space in between - example: JohnDoe): ";
	std::cin >> name;
	unsigned int numpassengers = 0;
	std::cout << "Enter number of passengers: ";
	std::cin >> numpassengers;
	std::list<std::pair<char, unsigned int>> seats;
	for (unsigned int i = 0; i < numpassengers; i++) {
		char c = ' ';
		// keep looping until we get a valid character Between A and Z
		while (c < 'A' || c > 'Z') {
			std::cout << "Select column for passenger " << i + 1 << " (A - Z): ";
			std::cin >> c;
		}
		unsigned int r = 0;
		// keep looping until we get a valid number between 1 and 25
		while (r < 1 || r >  25) {
			std::cout << "Select row for passenger " << i + 1 << " (1 - 25): ";
			std::cin >> r;
		}
		seats.push_back(std::make_pair(c, r));
	}
	// generate a unique number for reservation number
	unsigned int resnum = rand() % 1000 + 1;
	while (m_reservationlist.find(resnum) != m_reservationlist.end()) {
		resnum = rand() % 1000 + 1;
	}
	// create Reservation instance and add it to reservation list 
	Reservation res(resnum, name, numpassengers, seats);
	m_reservationlist[resnum] = res;
	double total_price = numpassengers * m_price;
	std::cout << "\nThank you. You total price is " << total_price << "$.\n";
	return resnum;
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
	// function of the destructor is to write out updated reservation info for each flight into it's corresponding text file
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