#include "TestHarness.h"
#include "Reservation.h"
#include <list>

TEST(DefaultConstructor, Reservation) {
	Reservation reservation;
	CHECK_EQUAL(0, reservation.getnumber());
	CHECK_EQUAL("---", reservation.getname());
	CHECK_EQUAL(0, reservation.getnumpassengers());
	CHECK(reservation.getseats().empty());
}

TEST(ParameterConstructor, Reservation) {
	std::list<std::pair<char, unsigned int>> seats;
	seats.push_back(std::make_pair('A', 5));
	seats.push_back(std::make_pair('B', 5));
	seats.push_back(std::make_pair('C', 5));
	Reservation reservation(122, "John Doe", 3, seats);
	CHECK_EQUAL(122, reservation.getnumber());
	CHECK_EQUAL("John Doe", reservation.getname());
	CHECK_EQUAL(3, reservation.getnumpassengers());
	CHECK(seats == reservation.getseats());
}

TEST(SetNewValues, Reservation) {
	std::list<std::pair<char, unsigned int>> seats;
	seats.push_back(std::make_pair('A', 5));
	seats.push_back(std::make_pair('B', 5));
	seats.push_back(std::make_pair('C', 5));
	Reservation reservation(122, "John Doe", 3, seats);
	CHECK_EQUAL(122, reservation.getnumber());
	CHECK_EQUAL("John Doe", reservation.getname());
	CHECK_EQUAL(3, reservation.getnumpassengers());
	CHECK(seats == reservation.getseats());
	reservation.setnumber(762);
	reservation.setname("Jonathan Littleman");
	reservation.setnumpassengers(2);
	seats.push_back(std::make_pair('K', 5));
	seats.push_back(std::make_pair('K', 6));
	reservation.setseats(seats);
	CHECK_EQUAL(762, reservation.getnumber());
	CHECK_EQUAL("Jonathan Littleman", reservation.getname());
	CHECK_EQUAL(2, reservation.getnumpassengers());
	CHECK(seats == reservation.getseats());
}

TEST(EqualToEqualToOperator, Reservation) {
	std::list<std::pair<char, unsigned int>> seats;
	seats.push_back(std::make_pair('A', 5));
	seats.push_back(std::make_pair('B', 5));
	seats.push_back(std::make_pair('C', 5));
	Reservation res1(122, "John Doe", 3, seats);
	Reservation res2(529, "John Foo", 3, seats);
	Reservation res3(122, "John Doe", 3, seats);
	CHECK(res1 != res2);
	CHECK(res1 == res3);
}