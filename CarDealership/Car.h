#pragma once

#include "Vehicle.h"

class Car : virtual public Vehicle {
private:
	int drivingSpeed;
	unsigned numOfWheels;

protected:
	virtual void toOs(std::ostream& out) const;

public:
	Car(const char* companyName, COLOR color, unsigned price, int drivingSpeed, unsigned numOfWheels);

	virtual bool operator>(const Vehicle& v);
	virtual bool operator==(const Vehicle& other);
	virtual void setPrice();
	virtual int getSpeed() const;
	virtual int getNumOfWheels() const;
};