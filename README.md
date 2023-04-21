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

**Implementation steps**
1. Create an instance of FlightList class. The constructor has following functions:  
    - Take in the path of [FlightList.txt](AirlineReservation/FlightDatabase/FlightList.txt). For every row in the FlightList.txt file, create a new instance of Flight class with corresponding info
    - Add each flight to a map (flight_list) where the key is flight number and value is Flight instance
2. Creating a new instance of Flight class invokes it's own constructor. The constructor has following functions:
    - Initialize flight instance with the corresponding info
    - Load reservation info from Flight<flight_number>.txt file if it is available. If the file is not available, create a new one. For each row of reservation, create a new instance of the Reservation class with corresponding info.
    - Add each reservation to a map (reservation_list) where the key is reservation number and value is Reservation class
3. Creating a new instance of Reservation class invokes it's own constructor. The constructor has following function:
    - Initialize reservation instance with the corresponding info
4. Display main menu to user and get their input
5. If user selects 'View available flights', display list of flights with the use of operator<< overloading in FlightList class and Flight class
6. If user selects 'Make reservation', call Flight::makereservation() - this function gets user input for reservation info, creates a Reservation instance and adds it to the reservation_list map
7. If user selects 'View existing reservation', call Flight::viewreservation(reservation_number) - this function looks up the reservation info from reservation_list using reservation_number and displays using operator<< overloading in Reservation class
8. If user selects 'Vancel existing reservation', call Flight::viewreservation(reservation_number) - this function looks up the reservation info from reservation_list using reservation_number and deletes the entry using [erase](https://en.cppreference.com/w/cpp/container/unordered_map/erase) function
9. If user selects 'Exit', then exit from the program
10. Finally, when the Flight class destructor is invoked, write out updated reservation info into corresponding Flight<flight_number>.txt file

 
