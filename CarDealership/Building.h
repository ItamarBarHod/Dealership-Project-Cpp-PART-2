#pragma once

#include "Address.h"

class Building : public Address {
private:
	int vehicleCapacity;
	int cost;
public:
	Building(const char* city, const char* street, unsigned houseNum, int vehicleCapacity, int cost);
	Building(Address& loc, int vehicleCapacity, int cost);

	unsigned getCapacity() const;
	unsigned getCost() const;
	void setCost(unsigned cost);
};