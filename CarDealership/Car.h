#include "Vehicle.h"

class Car : virtual public Vehicle {
private:
	int drivingSpeed;
	unsigned numOfWheels;
public:
	virtual void setPrice() const;
	virtual int getSpeed() const;
	virtual int getNumOfWheels() const;
};