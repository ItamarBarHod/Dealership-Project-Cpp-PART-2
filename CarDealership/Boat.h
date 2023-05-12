#pragma once

#include "Vehicle.h"

class Boat : virtual public Vehicle {
private:
	int sailingSpeed;
	int numOfSails;

protected:
	virtual void toOs(std::ostream& out) const;

public:
	Boat(const char* companyName, COLOR color, float price, int sailingSpeed, int numOfSails);

	virtual int getNumOfSails() const;
	virtual void setPrice();
	void setSail(int numOfSails);
};
