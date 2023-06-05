#pragma once

#include "Boat.h"
#include "Car.h"

class SuperBoatCar : public Boat, public Car {
private:
	float static turbo;

protected:
	std::ostream& toOs(std::ostream& out) const override;
	void setPrice() override;

public:
	SuperBoatCar(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels, int sailingSpeed, unsigned numOfSails);

	int getSpeed() const override; // MAX(sailspeed, driveSpeed)
	float getMaxSpeed() const; // turbo * getSpeed
	eVehicle getType() const override { return eSuperBoatCar; }
};

float SuperBoatCar::turbo = 1.5;