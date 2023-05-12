#pragma once

#include "Vehicle.h"

class Boat : virtual public Vehicle {
private:
	int sailingSpeed;
	int numOfSails;

protected:
	virtual void toOs(std::ostream& out) const;

public:
	Boat(const char* companyName, COLOR color, unsigned price, int sailingSpeed, int numOfSails);

	virtual bool operator>(const Vehicle& v);

	virtual int getSpeed() const;
	virtual int getNumOfSails() const;
	virtual void setPrice();
	void setSail(int numOfSails);
};
