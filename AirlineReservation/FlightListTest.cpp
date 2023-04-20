#ifdef _DEBUG
#include "TestHarness.h"
#include "FlightList.h"
#include "Flight.h"
#include <iostream>

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