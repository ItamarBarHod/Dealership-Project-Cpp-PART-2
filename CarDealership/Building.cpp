#include "Building.h"

Building::Building(const char* city, const char* street, unsigned houseNum, int vehicleCapacity, int cost)
	: address(city, street, houseNum), vehicleCapacity(vehicleCapacity), cost(cost)
{
}

Building::Building(const Address& loc, int vehicleCapacity, int cost) : address(loc), vehicleCapacity(vehicleCapacity), cost(cost)
{
}
