#pragma once

#include "Boat.h"
#include "Car.h"

class SuperBoatCar : public Boat, public Car {
private:
	float static turbo;

protected:
	void toOs(std::ostream& out) const;

public:
	SuperBoatCar(const char* companyName, COLOR color, float price, int drivingSpeed, unsigned numOfWheels, int sailingSpeed, unsigned numOfSails);
	void setPrice() override;
	bool operator>(const Vehicle& v);
	int getSpeed() const override; // MAX(sailspeed, driveSpeed)
	float getMaxSpeed() const; // turbo * getSpeed
};

float SuperBoatCar::turbo = 1.5;