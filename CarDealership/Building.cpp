#include "Building.h"

Building::Building(std::istream& in) : address(in)
{
	try {
		read(in);
	}
	catch (const char* msg) {
		throw msg;
	}
}

std::ostream& operator<<(std::ostream& out, const Building& place)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << place.address << " " << place.vehicleCapacity << " " << place.cost << " ";
	}
	else {
		out << place.address << "Capacity (max vehicles): " << place.vehicleCapacity
			<< ", Cost: " << place.cost << std::endl;
	}
	return out;
}

std::istream& Building::read(std::istream& in)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> vehicleCapacity >> cost;
	}
	else {
		std::cout << "Enter building capacity (max vehicles): ";
		in >> vehicleCapacity;
		if (vehicleCapacity < 1)
			throw "Cant initialize dealership without space for vehicles, please try again";
		std::cout << "Enter building cost: ";
		in >> cost;
	}
	return in;
}

std::istream& operator>>(std::istream& in, Building& place)
{
	return place.read(in);
}
