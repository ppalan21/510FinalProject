#pragma once
#include "Flight.h"
#include <unordered_map>

void add_flightlist_header(std::ostream& os);

class FlightList {
public:
	FlightList();
	FlightList(std::string);
	Flight& getflight(unsigned int flight_number);
	bool findflight(unsigned int flight_number) const;
	friend std::ostream& operator<<(std::ostream& os, const FlightList& flightlist);
private:
	std::unordered_map<unsigned int, Flight> m_list;
};