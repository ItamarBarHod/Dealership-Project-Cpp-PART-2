#pragma once

#include "Vehicle.h"

class Boat : virtual public Vehicle {
private:
	int sailingSpeed;
	int numOfSails;

protected:
	virtual std::ostream& toOs(std::ostream& out) const override;
	virtual void setPrice() override;

public:
	Boat(const char* companyName, eColor, float price, int sailingSpeed, int numOfSails);

	virtual int getNumOfSails() const;
	virtual int getSpeed() const;
	virtual eVehicle getType() const override { return eBoat; }

};
