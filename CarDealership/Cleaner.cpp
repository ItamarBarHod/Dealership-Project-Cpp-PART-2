#include "Cleaner.h"

Cleaner::Cleaner(std::istream& in) : Worker(in)
{
	read(in);
}

Cleaner::Cleaner(const char* name, Address** address, const Date& birthday, int salary, unsigned numOfAddresses, int maxSalesman, int salesmanCount) : Worker(name, address, birthday, salary, numOfAddresses), numOfCleanedVehicles(0)
{
}

void Cleaner::cleanVehicle(Vehicle& vec)
{
	bool isClean = vec.getCleanStatus();
	if (!isClean)
	{
		++vec;
		numOfCleanedVehicles++;
	}
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
