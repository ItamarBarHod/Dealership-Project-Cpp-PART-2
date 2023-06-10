#pragma once

#include "Boat.h"
#include "Car.h"

class SuperBoatCar : public Car, public Boat {
private:
	float static turbo;

protected:
	std::ostream& print(std::ostream& out) const override;
	std::istream& read(std::istream& in) override;

public:
	SuperBoatCar(std::istream& in);
	SuperBoatCar(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels, int sailingSpeed, unsigned numOfSails);

	int getSpeed() const override { return std::max(drivingSpeed, sailingSpeed); }
	float getMaxSpeed() const { return getSpeed() * turbo; }

	void raisePrice() override;
	int getType() const override { return eSuperBoatCar; }

	Vehicle* Clone() const { return new SuperBoatCar(*this); }
};