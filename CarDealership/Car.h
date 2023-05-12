#pragma once

#include "Vehicle.h"

class Car : virtual public Vehicle {
private:
	int drivingSpeed;
	unsigned numOfWheels;

protected:
	virtual void toOs(std::ostream& out) const;

public:
	Car(const char* companyName, COLOR color, float price, int drivingSpeed, unsigned numOfWheels);

	virtual void setPrice();
	virtual int getSpeed() const;
	virtual int getNumOfWheels() const;
};