#include "Location.h"

class Building : public Location {
private:
	unsigned vehicleCapacity;
	unsigned cost;
public:
	Building(const char* city, const char* street, unsigned houseNum, unsigned vehicleCapacity, unsigned cost);

	unsigned getCapacity() const;
	unsigned getCost() const;
	void setCost(unsigned cost);
};