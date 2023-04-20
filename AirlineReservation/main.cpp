#include "TestHarness.h"
#include "FlightList.h"
#include <iostream>
#include <iomanip>

enum class Menu {
	ListFlight,
	MakeReservation,
	ViewReservation,
	CancelReservation,
	Exit
};

int get_user_input() {
	std::cout << "Enter one of the options below:\n";
	std::cout << "\t1. View available flights\n";
	std::cout << "\t2. Make new reservation\n";
	std::cout << "\t3. View existing reservation\n";
	std::cout << "\t4. Cancel existing reservation\n";
	std::cout << "\t5. Exit\n";
	std::cout << "Option: ";
	int input = 0;
	std::cin >> input;
	return input;
}

Flight& check_and_get_flight(const FlightList& mylist) {
	std::cout << "Enter flight number to make reservation: ";
	unsigned int user_flight_num;
	std::cin >> user_flight_num;
	if (!mylist.findflight(user_flight_num)) {
		std::cout << "\nFlight number " << user_flight_num << " does not exist\n";
		std::cout << "\nAvailable flights:\n";
		std::cout << mylist;
		std::cout << "\nExiting..";
		exit(0);
	}
	Flight myflight = mylist.getflight(user_flight_num);
	return myflight;
}

int main() {
	// random number generator used in some tests
	srand(::time_t(NULL));

	TestResult tr;
	TestRegistry::runAllTests(tr);

	std::cout << "\n" << std::setfill('-') << std::setw(100) << "\n";
	std::cout << "Welcome to UW Airlines";
	std::cout << "\n" << std::setfill('-') << std::setw(100) << "\n";
	std::cout << "\n" << std::setfill(' ') << std::setw(100) << "\n";

	// Intitialize flight list from database
	FlightList mylist("FlightDatabase\\FlightList.txt");

	// Display user menu and get input from user
	int input = get_user_input();

	while (input != 5) {
		system("cls");
		if (input == 1) {
			std::cout << "\nAvailable flights:\n";
			std::cout << mylist << "\n";
		}
		else if (input == 2) {
			//Flight myflight = check_and_get_flight(mylist);
			//myflight.makereservation();
		}
		else if (input == 3) {
			//Flight myflight = check_and_get_flight(mylist);
			//Reservation myreservation = check_and_get_reservation(myflight);
		}
		else if (input == 4) {
			//Flight myflight = check_and_get_flight(mylist);
			//Reservation myreservation = check_and_get_reservation(myflight);
			//myflight.cancelreservation();
		}
		else {
			std::cout << "\nIncorrect option. Enter a valid option 1 - 5.\n\n";
		}
		input = get_user_input();
	}
	
	return 0;
}