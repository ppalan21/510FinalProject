#include "FlightList.h"
#include <iostream>
#include <iomanip>

#ifdef _DEBUG
#include "TestHarness.h"
#endif


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

int main() {
#ifdef _DEBUG
	std::cout << "\n" << std::setfill('-') << std::setw(100) << "\n";
	// random number generator used in some tests
	srand(::time_t(NULL));

	TestResult tr;
	TestRegistry::runAllTests(tr);
	std::cout << "Unit tests done!\n";
	std::cout << "\n" << std::setfill('-') << std::setw(100) << "\n";
	std::cout << "\n" << std::setfill(' ') << std::setw(100) << "\n";
	
#endif

	std::cout << "\n" << std::setfill('-') << std::setw(100) << "\n";
	std::cout << "Welcome to UW Airlines";
	std::cout << "\n" << std::setfill('-') << std::setw(100) << "\n";
	std::cout << "\n" << std::setfill(' ') << std::setw(100) << "\n";

	// intitialize flight list from database
	FlightList mylist("FlightDatabase\\FlightList.txt");

	// display user menu and get input from user
	int input = get_user_input();

	while (input != 5) {
		system("cls");

		// display available flights
		if (input == 1) {
			std::cout << "\nAvailable flights:\n";
			std::cout << mylist << "\n";
		}

		// if incorrect option, display message
		else if (input > 5) {
			std::cout << "\nIncorrect option. Enter a valid option 1 - 5.\n\n";
		}

		// if input = 2, 3, or 4
		else {
			// get flight number to make/view/cancel reservation
			std::cout << "Enter flight number to make/view/cancel reservation: ";
			unsigned int user_flight_num;
			std::cin >> user_flight_num;
			// check validity of flight number
			if (!mylist.findflight(user_flight_num)) {
				std::cout << "Flight number " << user_flight_num << " does not exist\n";
				std::cout << "\nAvailable flights:\n";
				std::cout << mylist;
				std::cout << "\n";
			}
			else {
				// get the correct flight
				Flight& myflight = mylist.getflight(user_flight_num);
				// make a new reservation
				if (input == 2) {
					unsigned int resnum = myflight.makereservation();
					std::cout << "Your reservation number is: " << resnum << " (Please save this for future reference)\n\n";
				}
				else {
					// get reservation number to view or cancel it
					std::cout << "Enter reservation number: ";
					unsigned int user_res_num;
					std::cin >> user_res_num;
					// check validity of reservation number
					if (!myflight.findreservation(user_res_num)) {
						std::cout << "Reservation number " << user_res_num << " does not exist\n\n";
					}
					else {
						// view reservation
						if (input == 3) {
							add_reservationlist_header(std::cout);
							Reservation& myreservation = myflight.getreservation(user_res_num);
							std::cout << myreservation << "\n";
						}
						// cancel reservation
						else {
							myflight.cancelreservation(user_res_num);
						}
					}
				}
			}
		}
		input = get_user_input();
	}
	
	return 0;
}