#ifndef CAR_H
#define CAR_H
#pragma once

#include "Vehicle.h"

class Car : virtual public Vehicle {
protected:
	int drivingSpeed;
	unsigned numOfWheels;

protected:
	virtual std::ostream& print(std::ostream& out) const override;
	virtual std::istream& read(std::istream& in) override;

public:
	Car(std::istream& in);
	Car(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels);

	virtual int getNumOfWheels() const { return numOfWheels; }
	virtual int getSpeed() const { return drivingSpeed; }

	virtual void raisePrice() override;
	virtual int getType() const override { return eCar; }

	Vehicle* Clone() const { return new Car(*this); }
};

#endif