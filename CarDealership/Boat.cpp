#include "Boat.h"

Boat::Boat() : sailingSpeed(0), numOfSails(0)
{
}

Boat::Boat(std::istream& in) : Vehicle(in), numOfSails(0), sailingSpeed(0)
{
	in >> *this;
}

Boat::Boat(const Boat& other) : Vehicle(other), numOfSails(0), sailingSpeed(0)
{
}

Boat::Boat(Boat&& other) noexcept : Vehicle(std::move(other)), numOfSails(0), sailingSpeed(0)
{
}

Boat::Boat(const char* companyName, eColor color, float price, int sailingSpeed, int numOfSails)
	: Vehicle(companyName, color, price), sailingSpeed(sailingSpeed), numOfSails(numOfSails)
{
}

Boat::~Boat()
{
}

Boat& Boat::operator=(const Boat& other)
{
	return *this;
}

Boat& Boat::operator=(Boat&& other) noexcept
{
	return *this;
}


std::ostream& Boat::print(std::ostream& out) const
{
	Vehicle::print(out);
	if (typeid(out) == typeid(std::ofstream))
	{
		out << sailingSpeed << " " << numOfSails << std::endl;
	}
	else {
		out << "Boat speed: " << sailingSpeed << ", number of sails: " << numOfSails << std::endl;
	}
	return out;
}

std::istream& Boat::read(std::istream& in)
{
	Vehicle::read(in);
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> sailingSpeed >> numOfSails;
	}
	else {
		std::cout << "Enter sailing speed: ";
		in >> sailingSpeed;
		std::cout << "Enter number of sails: ";
		in >> numOfSails;
	}
	return in;
}

void Boat::raisePrice()
{
	price *= factorArr[eBoat];
}