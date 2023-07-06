#include "Boat.h"

Boat::Boat(std::istream& in) : Vehicle(in)
{
	read(in);
}

Boat::Boat(const std::string& companyName, eColor color, float price, int sailingSpeed, int numOfSails)
	: Vehicle(companyName, color, price), sailingSpeed(sailingSpeed), numOfSails(numOfSails)
{
}

Boat::~Boat()
{
}

std::ostream& Boat::print(std::ostream& out) const
{
	Vehicle::print(out);
	if (typeid(out) == typeid(std::ofstream))
	{
		out << sailingSpeed << " " << numOfSails << std::endl;
	}
	else {
		out << "Boat speed: " << sailingSpeed << ", number of sails: " << numOfSails << "\n\n";
	}
	return out;
}

std::istream& Boat::read(std::istream& in)
{
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