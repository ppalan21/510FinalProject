#ifdef _DEBUG
#include "TestHarness.h"
#include "FlightList.h"
#include "Flight.h"
#include <fstream>

TEST(DefaultConstructor, FlightList) {
	FlightList flist;
	std::stringstream ss_expected, ss_actual;
	add_flightlist_header(ss_expected);
	ss_actual << flist;
	CHECK_EQUAL(ss_expected.str(), ss_actual.str());
}

TEST(CheckNumFlights, FlightList) {
	std::string filepath = "FlightDatabase\\FlightList.txt";
	FlightList flist(filepath);
	unsigned int numrows = 0;
	std::ifstream myfile(filepath);
	std::string line;
	while (std::getline(myfile, line)) {
		++numrows;
	}
	// ignore the header row
	numrows -= 1;
	if (numrows != flist.getnumflights()) {
		CHECK_FAIL("Number of flights mismatching. Check if same flight number is defined more than once in FlightList.txt");
	}
}

TEST(GetFlight, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	Flight actualfl = flist.getflight(745);
	Flight expectedfl(745, "SMF", "MAA", 1700, 121, 245.43);
	CHECK_EQUAL(expectedfl, actualfl);
}

TEST(FindFlight, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	CHECK(flist.findflight(745));
	CHECK(!flist.findflight(123));
}
#endif