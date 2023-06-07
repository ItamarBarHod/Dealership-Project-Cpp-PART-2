#pragma once

#include "Address.h"

class Building {
private:
	Address address;
	unsigned vehicleCapacity;
	unsigned cost;

public:
	Building();
	Building(std::ifstream& inFile);
	Building(const char* city, const char* street, unsigned houseNum, int vehicleCapacity, int cost);
	Building(const Address& loc, int vehicleCapacity, int cost);


	friend std::ostream& operator<<(std::ostream& out, const Building& place);
	friend std::istream& operator>>(std::istream& in, Building& place);

	const Address& getAddress() const { return address; }
	unsigned getCapacity() const { return vehicleCapacity; }
	unsigned getCost() const { return cost; }
};