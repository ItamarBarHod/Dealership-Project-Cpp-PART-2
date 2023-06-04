#pragma once

#include "Boat.h"
#include "Car.h"

class SuperBoatCar : public Boat, public Car {
private:
	float static turbo;

protected:
	void toOs(std::ostream& out) const;
	void setPrice() override;

public:
	SuperBoatCar(const char* companyName, COLOR color, float price, int drivingSpeed, unsigned numOfWheels, int sailingSpeed, unsigned numOfSails);

	int getSpeed() const override; // MAX(sailspeed, driveSpeed)
	float getMaxSpeed() const; // turbo * getSpeed
};

float SuperBoatCar::turbo = 1.5;