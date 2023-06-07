#pragma once

#include "Vehicle.h"

class Boat : virtual public Vehicle {
protected:
	int sailingSpeed;
	int numOfSails;

protected:
	virtual std::ostream& print(std::ostream& out) const override;
	virtual std::istream& read(std::istream& in) override;

public:
	Boat();
	Boat(std::istream& in);
	Boat(const Boat& other);
	Boat(Boat&& other) noexcept;
	Boat(const char* companyName, eColor color, float price, int sailingSpeed, int numOfSails);
	virtual ~Boat();

	Boat& operator=(const Boat& other);
	Boat& operator=(Boat&& other) noexcept;


	virtual int getNumOfSails() const { return numOfSails; }
	virtual int getSpeed() const { return sailingSpeed; }

	virtual void raisePrice() override;

	Vehicle* Clone() const { return new Boat(*this); }
};
