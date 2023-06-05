#pragma once

#include "Address.h"

class Building {
private:
	Address address;
	unsigned vehicleCapacity;
	unsigned cost;

public:
	Building(const char* city, const char* street, unsigned houseNum, int vehicleCapacity, int cost);
	Building(const Address& loc, int vehicleCapacity, int cost);


	friend std::ostream& operator<<(std::ostream& out, const Building& place);
	friend std::istream& operator>>(std::istream& in, Building& place);

	const Address& getAddress() const { return address; }
	unsigned getCapacity() const { return vehicleCapacity; }
	unsigned getCost() const { return cost; }
};

std::ostream& operator<<(std::ostream& out, const Building& place)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << place.vehicleCapacity << " " << place.cost << " " << place.address << std::endl;
	}
	else {
		out << "Building capacity: " << place.vehicleCapacity
			<< "Cost: " << place.cost << "Address: " << place.address << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Building& place)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		char delimiter;
		in >> place.vehicleCapacity >> delimiter >> place.cost >> delimiter >> place.address;
	}
	else {
		std::cout << "enter capacity, cost(int) and address\n";
		in >> place.vehicleCapacity >> place.cost >> place.address;
	}
	return in;
}