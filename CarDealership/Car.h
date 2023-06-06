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
	Car();
	Car(std::ifstream& inFile);
	Car(const Car& other);
	Car(Car&& other) noexcept;
	Car(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels);
	virtual ~Car();

	Car& operator=(const Car& other);
	Car& operator=(Car&& other) noexcept;


	virtual int getNumOfWheels() const { return numOfWheels; }
	virtual int getSpeed() const { return drivingSpeed; }

	virtual void raisePrice() override;

	Vehicle* Clone() const { return new Car(*this); }
};