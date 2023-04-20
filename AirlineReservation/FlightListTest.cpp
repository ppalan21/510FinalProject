#ifdef _DEBUG
#include "TestHarness.h"
#include "FlightList.h"
#include "Flight.h"
#include <iostream>

TEST(LoadFromFilePath, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	std::stringstream ss_actual;
	ss_actual << flist;
	std::stringstream ss_expected;
	add_flightlist_header(ss_expected);
	Flight fl1 = flist.getflight(745);
	ss_expected << fl1;
	Flight fl2 = flist.getflight(821);
	ss_expected << fl2;
	Flight fl3 = flist.getflight(121);
	ss_expected << fl3;
	CHECK_EQUAL(ss_expected.str(), ss_actual.str());
}

TEST(GetFlight, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	Flight actualfl = flist.getflight(821);
	Flight expectedfl(821,"KLM", "CVV", 1220, 56, 74.89);
	CHECK_EQUAL(expectedfl, actualfl);
}

TEST(FindFlight, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	CHECK(flist.findflight(745));
	CHECK(!flist.findflight(123));
}
#endif