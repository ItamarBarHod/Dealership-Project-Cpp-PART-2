#pragma once

#include "Vehicle.h"

class Car : virtual public Vehicle {
private:
	int drivingSpeed;
	unsigned numOfWheels;

protected:
	virtual void toOs(std::ostream& out) const;
	virtual void setPrice();

public:
	Car(const char* companyName, COLOR color, float price, int drivingSpeed, unsigned numOfWheels);

	virtual int getNumOfWheels() const;
	virtual int getSpeed() const;
};