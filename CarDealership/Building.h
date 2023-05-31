#pragma once

#include "Address.h"

class Building {
private:
	int vehicleCapacity;
	int cost;
	Address address;
public:
	Building(const char* city, const char* street, unsigned houseNum, int vehicleCapacity, int cost);
	Building(Address& loc, int vehicleCapacity, int cost);

	unsigned getCapacity() const;
	unsigned getCost() const;
};