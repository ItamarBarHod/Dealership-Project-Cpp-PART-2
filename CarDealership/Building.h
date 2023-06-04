#pragma once

#include "Address.h"

class Building {
private:
	unsigned vehicleCapacity;
	unsigned cost;
	Address address;

public:
	Building(const char* city, const char* street, unsigned houseNum, int vehicleCapacity, int cost);
	Building(Address& loc, int vehicleCapacity, int cost);

	unsigned getCapacity() const { return vehicleCapacity; }
	unsigned getCost() const { return cost; }
};