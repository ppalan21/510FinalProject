#include "TestHarness.h"
#include "Flight.h"

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
	Flight flight(845, "SMF", "MAA", 1730, 121, 234.11);
	std::stringstream ss;
	ss << flight;
	CHECK_EQUAL("***\nFlight 845 details:\nSMF --> MAA\nStart time: 1730 PST\nDuration: 121 minutes\nPrice per seat: 234.11 $\n***\n", ss.str());
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
	ss.str("");
	ss << flight;
	CHECK_EQUAL(762, flight.getnumber());
	CHECK_EQUAL("ABC", flight.getsource());
	CHECK_EQUAL("RDD", flight.getdestination());
	CHECK_EQUAL(1230, flight.getstarttime());
	CHECK_EQUAL(181, flight.getduration());
	CHECK_DOUBLES_EQUAL(411.11, flight.getprice(), 0.01);
}