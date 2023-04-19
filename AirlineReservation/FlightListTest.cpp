#include "TestHarness.h"
#include "FlightList.h"
#include "Flight.h"
#include <iostream>

TEST(LoadFromFilePath, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	std::stringstream ss_actual;
	ss_actual << flist;
	std::stringstream ss_expected;
	table_header(ss_expected);
	Flight fl1(845, "SMF", "MAA", 1730, 121, 234.114);
	ss_expected << fl1 << "\n";
	Flight fl2(762, "ABC", "KVM", 1220, 56, 102.33);
	ss_expected << fl2 << "\n";
	Flight fl3(253, "XYZ", "QWQ", 410, 232, 520.65);
	ss_expected << fl3 << "\n";
	CHECK_EQUAL(ss_expected.str(), ss_actual.str());
}

TEST(GetFlight, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	Flight actualfl = flist.getflight(762);
	Flight expectedfl(762, "ABC", "KVM", 1220, 56, 102.33);
	CHECK_EQUAL(expectedfl, actualfl);
}

TEST(FindFlight, FlightList) {
	FlightList flist("FlightDatabase\\FlightList.txt");
	CHECK(flist.findflight(845));
	CHECK(!flist.findflight(123));
}