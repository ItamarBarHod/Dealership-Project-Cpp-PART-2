#include "Cleaner.h"

Cleaner::Cleaner(std::istream& in) : Worker(in)
{
	read(in);
}

Cleaner::Cleaner(const std::string& name, const LinkedList<Address*>& address, const Date& birthday, int salary)
	: Worker(name, address, birthday, salary), numOfCleanedVehicles(0)
{
}

void Cleaner::cleanVehicle(Vehicle& vec)
{
	bool isClean = vec.getCleanStatus();
	if (isClean)
		throw std::invalid_argument("Vehicle is already clean");
	++vec;
	numOfCleanedVehicles++;
}

std::ostream& Cleaner::print(std::ostream& out) const
{
	Worker::print(out);
	if (typeid(out) == typeid(std::ofstream))
	{
		out << numOfCleanedVehicles;
	}
	else {
		std::cout << "Cleaned vehicles: " << numOfCleanedVehicles << std::endl;
	}
	return out;
}

std::istream& Cleaner::read(std::istream& in)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> numOfCleanedVehicles;
	}
	return in;
}

std::istream& operator>>(std::istream& in, Cleaner& cleaner)
{
	return cleaner.read(in);
}
