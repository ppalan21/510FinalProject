#pragma once
#include "Reservation.h"
#include <string>
#include <unordered_map>

void add_reservationlist_header(std::ostream&);

class Flight {
public:
	Flight();
	Flight(unsigned int, std::string, std::string, unsigned int, unsigned int, double);
	unsigned int getnumber() const;
	std::string getsource() const;
	std::string getdestination() const;
	unsigned int getstarttime() const;
	unsigned int getduration() const;
	double getprice() const;
	void setnumber(unsigned int);
	void setsource(std::string);
	void setdestination(std::string);
	void setstarttime(unsigned int);
	void setduration(unsigned int);
	void setprice(double);
	Reservation& getreservation(unsigned int);
	bool findreservation(unsigned int) const;
	void makereservation();
	void cancelreservation(unsigned int);
	bool operator== (Flight& other);
	friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
	~Flight();
private:
	unsigned int m_number;
	std::string m_source;
	std::string m_destination;
	unsigned int m_start_time;
	unsigned int m_duration;
	double m_price;
	std::unordered_map<unsigned int, Reservation> m_reservationlist;
};
