#pragma once

#include "Boat.h"
#include "Car.h"

class SuperBoatCar : public Boat, public Car {
protected:
	void toOs(std::ostream& out) const;

public:
	SuperBoatCar(const char* companyName, COLOR color, float price, int drivingSpeed, unsigned numOfWheels, int sailingSpeed, unsigned numOfSails);

	void setPrice() override;
};
