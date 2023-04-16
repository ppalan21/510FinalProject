#pragma once
#include <string>

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
	friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
private:
	unsigned int m_number;
	std::string m_source;
	std::string m_destination;
	unsigned int m_start_time;
	unsigned int m_duration;
	double m_price;
};
