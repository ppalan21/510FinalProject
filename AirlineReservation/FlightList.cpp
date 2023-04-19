#include "FlightList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

void table_header(std::ostream& os) {
	os << "Number" << std::setw(15)
		<< "Source" << std::setw(15)
		<< "Destination" << std::setw(15)
		<< "Start(PST)" << std::setw(15)
		<< "Dur(min)" << std::setw(15)
		<< "Price($)\n";
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
		table_header(std::cout);
		exit(0);
	}
}

Flight FlightList::getflight(unsigned int num) const {
	return m_list.at(num);
}

std::ostream& operator<<(std::ostream& os, const FlightList& fl) {
	table_header(os);
	for (const auto& entry : fl.m_list) {
		os << entry.second << "\n";
	}
	return os;
}