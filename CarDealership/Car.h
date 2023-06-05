#pragma once

#include "Vehicle.h"

class Car : virtual public Vehicle {
private:
	int drivingSpeed;
	unsigned numOfWheels;

protected:
	virtual std::ostream& toOs(std::ostream& out) const override;
	virtual void setPrice() override;

public:
	Car(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels);

	virtual int getNumOfWheels() const;
	virtual int getSpeed() const;
	virtual eVehicle getType() const override { return eCar; }
};