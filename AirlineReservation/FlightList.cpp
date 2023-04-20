#include "FlightList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <format>

void add_flightlist_header(std::ostream& os) {
	os	<< std::format("{:<25}", "Flight Number")
		<< std::format("{:<25}", "Source")
		<< std::format("{:<25}", "Destination")
		<< std::format("{:<25}", "Start time (PST)")
		<< std::format("{:<25}", "Duration (min)")
		<< std::format("{:<25}", "Price ($)");
	os << "\n";
}

FlightList::FlightList() {

}

FlightList::FlightList(std::string filepath) {
	std::ifstream mylist(filepath);
	if (mylist.is_open()) {
		std::string mytext;
		int current_line = -1;
		while (std::getline(mylist, mytext)) {
			current_line++;
			if (current_line == 0) continue;
			std::stringstream ss;
			ss << mytext;
			unsigned int num, st, dur;
			std::string src, dst;
			double price;
			ss >> num >> src >> dst >> st >> dur >> price;
			if (!ss) {
				std::cout << "Flight details for row " << current_line << " not parsed correctly\n";
				exit(0);
			}
			Flight flight(num, src, dst, st, dur, price);
			m_list[num] = flight;
		}
		mylist.close();
	}
	else {
		std::cout << "Flight database file at " << filepath << " is not available. Please create one in the following format: \n\n";
		add_flightlist_header(std::cout);
		exit(0);
	}
}

Flight FlightList::getflight(unsigned int num) const {
	return m_list.at(num);
}

bool FlightList::findflight(unsigned int flight_number) const {
	if (m_list.find(flight_number) != m_list.end()) return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const FlightList& fl) {
	add_flightlist_header(os);
	for (const auto& entry : fl.m_list) {
		os << entry.second;
	}
	return os;
}