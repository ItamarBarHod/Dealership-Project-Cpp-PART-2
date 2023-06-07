#include "Building.h"

Building::Building() : cost(0), vehicleCapacity(0)
{
}

Building::Building(std::ifstream& inFile) : cost(0), vehicleCapacity(0)
{
	inFile >> *this;
}

Building::Building(const char* city, const char* street, unsigned houseNum, int vehicleCapacity, int cost)
	: address(city, street, houseNum), vehicleCapacity(vehicleCapacity), cost(cost)
{
}

Building::Building(const Address& loc, int vehicleCapacity, int cost) : address(loc), vehicleCapacity(vehicleCapacity), cost(cost)
{
}

std::ostream& operator<<(std::ostream& out, const Building& place)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << place.vehicleCapacity << " " << place.cost << " " << place.address << std::endl;
	}
	else {
		out << place.address << "Capacity (max vehicles): " << place.vehicleCapacity
			<< ", Cost: " << place.cost << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Building& place)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> place.vehicleCapacity >> place.cost >> place.address;
	}
	else {
		std::cout << "Enter building capacity: ";
		in >> place.vehicleCapacity;
		std::cout << "Enter building cost: ";
		in >> place.cost;
		in.ignore();
		in >> place.address;
	}
	return in;
}