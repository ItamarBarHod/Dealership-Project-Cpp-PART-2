#include "Boat.h"
#include "Car.h"

class SuperBoatCar : public Boat, public Car {
private:
	float static turbo;
public:
	void setPrice() const override;
	int getSpeed() const override; // MAX(sailspeed, driveSpeed)
	float getMaxSpeed() const; // turbo * getSpeed
};

float SuperBoatCar::turbo = 1.5;