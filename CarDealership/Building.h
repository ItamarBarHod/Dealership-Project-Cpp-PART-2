#ifndef BUILDING_H
#define BUILDING_H
#pragma once


#include "Address.h"

class Building {
private:
	Address address;
	unsigned vehicleCapacity;
	unsigned cost;

private:
	std::istream& read(std::istream& in);

public:
	Building(std::istream& in);

	friend std::ostream& operator<<(std::ostream& out, const Building& place);
	friend std::istream& operator>>(std::istream& in, Building& place);

	const Address& getAddress() const { return address; }
	unsigned getCapacity() const { return vehicleCapacity; }
	unsigned getCost() const { return cost; }
};

#endif