# UW510 FinalProject - Airline Reservation System
Prashanth Palaniappan

## Objective
The goal of this project is to create an Airline reservation system where customers can view available flights, create new reservations, view existing reservations and cancel existing reservations. Reservation info will be persisted across multiple runs by storing it in an offline text file.

Main menu visible to customers:
- View available flights : This will display a list of available flights in the following format:<br/>
 Flight Number &emsp;&emsp; Source &emsp;&emsp; Destination &emsp;&emsp; Start time (PST) &emsp;&emsp; Duration (min) &emsp;&emsp; Price ($)
- Make new reservation : This will get user input and create reservation in following format:<br/>
 ReservationNumber &emsp;&emsp; PassengerName &emsp;&emsp; NumberOfPassengers &emsp;&emsp; Seats
- View existing reservation : Customers can lookup reservation info based on input flight number and reservation number
- Cancel existing reservation : Customers can delete reservation based on input flight number and reservation number

## Implementation
### High-level implementation idea
We have a Flight database file ([FlightList.txt](AirlineReservation/FlightDatabase/FlightList.txt)) that contains a list of flights and their corresponding info. Flights can be added into this file using this format:
 Flight Number &emsp;&emsp; Source &emsp;&emsp; Destination &emsp;&emsp; Start time (PST) &emsp;&emsp; Duration (min) &emsp;&emsp; Price ($)<br/>
or existing flights can be deleted from this file.<br/>
For each flight, we have a text file called Flight<flight_number>.txt that is used to hold the reservation info across multiple runs. If this file does not exist, a new one will be created. If it already exists, it will be updated with new reservations.

We have 3 classes implemented for this project
- FlightList
- Flight
- Reservation

### Implementation steps
1. Create an instance of FlightList class. The constructor has following functions:  
    - Take in the path of [FlightList.txt](AirlineReservation/FlightDatabase/FlightList.txt). For every row in the FlightList.txt file, create a new instance of Flight class with corresponding info
    - Add each flight to a map (flight_list) where the key is flight number and value is Flight instance
2. Creating a new instance of Flight class invokes it's own constructor. The constructor has following functions:
    - Initialize Flight instance with the corresponding info
    - Load reservation info from Flight<flight_number>.txt file if it is available. If the file is not available, create a new one. For each row of reservation, create a new instance of the Reservation class with corresponding info.
    - Add each reservation to a map (reservation_list) where the key is reservation number and value is Reservation instance
3. Creating a new instance of Reservation class invokes it's own constructor. The constructor has following function:
    - Initialize Reservation instance with the corresponding info
4. Display main menu to user and get their input
5. If user selects 'View available flights', display list of flights with the use of operator<< overloading in FlightList class and Flight class
6. If user selects 'Make reservation', call Flight::makereservation() - this function gets user input for reservation info, creates a Reservation instance and adds it to the reservation_list map
7. If user selects 'View existing reservation', call Flight::viewreservation(reservation_number) - this function looks up the reservation info from reservation_list using reservation_number and displays using operator<< overloading in Reservation class
8. If user selects 'Vancel existing reservation', call Flight::viewreservation(reservation_number) - this function looks up the reservation info from reservation_list using reservation_number and deletes the entry using [erase](https://en.cppreference.com/w/cpp/container/unordered_map/erase) function
9. If user selects 'Exit', then exit from the program
10. Finally, when the Flight class destructor is invoked, write out updated reservation info into corresponding Flight<flight_number>.txt file

### Classes and their responsibilities
#### UML
#### class FlightList
_-std::unordered_map<unsigned int, Flight> m_list_ - maps Flight number to it's corresponding Flight instance<br/>
_-unsigned int m_num_flights_ - keeps count of number of available flights<br/>
_+FlightList()_ - Default constructor<br/>
_+FlightList(std::string)_ - Refer to point no.1 in [Implementation steps](README.md#implementation-steps)<br/>
_+Flight& getflight(unsigned int flight_number)_ - Get Flight instance based on flight_number<br/>
_+bool findflight(unsigned int flight_number) const_ - Check if a Flight instance exists or not, based on flight_number<br/>
_+unsigned int getnumflights() const_ - Get number of available flights<br/>
_+friend std::ostream& operator<<(std::ostream& os, const FlightList& flightlist)_ - Ostream operator overloading<br/>
#### class Flight
_-unsigned int m_number_ - Flight number<br/>
_-std::string m_source_ - Flight source city represented as three letters<br/>
_-std::string m_destination_ - Flight destination city represented as three letters<br/>
_-unsigned int m_start_time_ - Flight start time (PST)<br/>
_-unsigned int m_duration_ - Flight duration (minutes)<br/>
_-double m_price_ - Flight price per seat ($)<br/>
_-std::unordered_map<unsigned int, Reservation> m_reservationlist_ - maps Reservation number to it's corresponding Reservation instance<br/>
_+Flight()_ - Default constructor<br/>
_+Flight(unsigned int, std::string, std::string, unsigned int, unsigned int, double)_ - Refer to point no.2 in [Implementation steps](README.md#implementation-steps)<br/>
_+unsigned int getnumber() const_ - Get flight number<br/>
_+std::string getsource() const_ - Get flight source city<br/>
_+std::string getdestination() const_ - Get flight destination city<br/>
_+unsigned int getstarttime() const_ - Get flight start time<br/>
_+unsigned int getduration() const_ - Get flight suration<br/>
_+double getprice() const_ - Get flight price per seat<br/>
_+void setnumber(unsigned int)_ - Set flight number<br/>
_+void setsource(std::string)_ - Set flight source city<br/>
_+void setdestination(std::string)_ - Set flight destination city<br/>
_+void setstarttime(unsigned int)_ - Set flight start time<br/>
_+void setduration(unsigned int)_ - Set flight duration<br/>
_+void setprice(double)_ - Set flight price<br/>
_+Reservation& getreservation(unsigned int)_ - Get Reservation instance using reservation number<br/>
_+bool findreservation(unsigned int) const_ - Find if a specific reservation is valid or not<br/>
_+unsigned int makereservation()_ - Make a reservation<br/>
_+void cancelreservation(unsigned int)_ - Delete reservation using reservation number<br/>
_+bool operator== (Flight& other)_ - operator== overloading<br/>
_+friend std::ostream& operator<<(std::ostream& os, const Flight& flight)_ - Ostream operator overloading<br/>
_+~Flight()_ - Refer to point no.10 in [Implementation steps](README.md#implementation-steps)<br/>
#### class Reservation
_-unsigned int m_number_ - <br/>
_-std::string m_name_ - <br/>
_-unsigned int m_numpassengers_ - <br/>
_-std::list<std::pair<char, unsigned int>> m_seats_ - <br/>
_+Reservation()_ - <br/>
_+Reservation(unsigned int, std::string, unsigned int, std::list<std::pair<char, unsigned int>>&)_ - <br/> 
_+unsigned int getnumber() const_ - <br/>
_+std::string getname() const_ - <br/>
_+unsigned int getnumpassengers() const_ - <br/> 
_+std::list<std::pair<char, unsigned int>> getseats() const_ - <br/>
_+void setnumber(unsigned int)_ - <br/>
_+void setname(std::string)_ - <br/>
_+void setnumpassengers(unsigned int)_ - <br/>
_+void setseats(std::list<std::pair<char, unsigned int>>&)_ - <br/>
_+bool operator== (Reservation& other)_ - <br/>
_+friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation)_ - <br/>

## Testing
The CppUnitLite test framework was used for testing the public member functions of the classes. <class_name>Test.cpp contains the unit tests for each class.

## Next steps
Unfortunately, I did not have time to finish seat map and seat selection support. A few next steps that can be considered:
- Seat map support
- Payment support
- Waitlist mechanism using circular data structure (if flight is full)
