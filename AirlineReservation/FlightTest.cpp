#ifdef _DEBUG
#include "TestHarness.h"
#include "Flight.h"
#include <format>
#include <iostream>

TEST(DefaultConstructor, Flight) {
	Flight flight;
	CHECK_EQUAL(0, flight.getnumber());
	CHECK_EQUAL("---", flight.getsource());
	CHECK_EQUAL("---", flight.getdestination());
	CHECK_EQUAL(0, flight.getstarttime());
	CHECK_EQUAL(0, flight.getduration());
	CHECK_DOUBLES_EQUAL(0, flight.getprice(), 0.01);
}

TEST(ParameterConstructor, Flight) {
	Flight flight(845, "SMF", "MAA", 1730, 121, 234.11);
	CHECK_EQUAL(845, flight.getnumber());
	CHECK_EQUAL("SMF", flight.getsource());
	CHECK_EQUAL("MAA", flight.getdestination());
	CHECK_EQUAL(1730, flight.getstarttime());
	CHECK_EQUAL(121, flight.getduration());
	CHECK_DOUBLES_EQUAL(234.11, flight.getprice(), 0.01);
}

TEST(OstreamOperator, Flight) {
	std::stringstream ss_expected;
	ss_expected << std::format("{:<25}", 845)
		<< std::format("{:<25}", "SMF")
		<< std::format("{:<25}", "MAA")
		<< std::format("{:<25}", 1730)
		<< std::format("{:<25}", 121)
		<< std::format("{:<25}", 234.11);
	ss_expected << "\n";
	Flight flight(845, "SMF", "MAA", 1730, 121, 234.11);
	std::stringstream ss_actual;
	ss_actual << flight;
	CHECK_EQUAL(ss_expected.str(), ss_actual.str());
}


TEST(SetNewValues, Flight) {
	Flight flight(845, "SMF", "MAA", 1730, 121, 234.11);
	std::stringstream ss;
	ss << flight;
	CHECK_EQUAL(845, flight.getnumber());
	CHECK_EQUAL("SMF", flight.getsource());
	CHECK_EQUAL("MAA", flight.getdestination());
	CHECK_EQUAL(1730, flight.getstarttime());
	CHECK_EQUAL(121, flight.getduration());
	CHECK_DOUBLES_EQUAL(234.11, flight.getprice(), 0.01);
	flight.setnumber(762);
	flight.setsource("ABC");
	flight.setdestination("RDD");
	flight.setstarttime(1230);
	flight.setduration(181);
	flight.setprice(411.11);
	CHECK_EQUAL(762, flight.getnumber());
	CHECK_EQUAL("ABC", flight.getsource());
	CHECK_EQUAL("RDD", flight.getdestination());
	CHECK_EQUAL(1230, flight.getstarttime());
	CHECK_EQUAL(181, flight.getduration());
	CHECK_DOUBLES_EQUAL(411.11, flight.getprice(), 0.01);
}

TEST(EqualToEqualToOperator, Flight) {
	Flight fl1(845, "SMF", "MAA", 1730, 121, 234.11);
	Flight fl2(845, "SMF", "MAA", 1730, 121, 234.11);
	Flight fl3(253, "XYZ", "QWQ", 410, 232, 520.65);
	CHECK(fl1 == fl2);
	CHECK(fl1 != fl3);
}

TEST(ReservationActions, Flight) {
	Flight fl(845, "SMF", "MAA", 1730, 121, 234.11);
	// Make reservation
	std::cout << "This is a debug test case to create a new reservation:\n";
	unsigned int resnum = fl.makereservation();
	std::cout << "Your reservation number is: " << resnum << " (Please save this for future reference)\n\n";
	// view and check reservation
	if (!fl.findreservation(resnum)) {
		CHECK_FAIL("Reservation not added correctly");
	}
	// cancel reservation
	fl.cancelreservation(resnum);
	if (fl.findreservation(resnum)) {
		CHECK_FAIL("Reservation not cancelled correctly");
	}
	std::cout << "\n";
}
#endif