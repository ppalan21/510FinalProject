#pragma once
#include <string>
#include <list>

void add_reservationlist_header(std::ostream&);

class Reservation {
public:
	Reservation();
	Reservation(unsigned int, std::string, unsigned int, std::list<std::pair<char, unsigned int>>&);
	unsigned int getnumber() const;
	std::string getname() const;
	unsigned int getnumpassengers() const;
	std::list<std::pair<char, unsigned int>> getseats() const;
	void setnumber(unsigned int);
	void setname(std::string);
	void setnumpassengers(unsigned int);
	void setseats(std::list<std::pair<char, unsigned int>>&);
	bool operator== (Reservation& other);
	friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
private:
	unsigned int m_number;
	std::string m_name;
	unsigned int m_numpassengers;
	std::list<std::pair<char, unsigned int>> m_seats;
};