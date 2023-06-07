#include "SuperBoatCar.h"

float SuperBoatCar::turbo = 1.5F;

SuperBoatCar::SuperBoatCar()
{
}

SuperBoatCar::SuperBoatCar(std::istream& in) : Vehicle(in)
{
	in >> *this;
}

SuperBoatCar::SuperBoatCar(const SuperBoatCar& other)
{

}

SuperBoatCar::SuperBoatCar(SuperBoatCar&& other) noexcept
{
}

SuperBoatCar::SuperBoatCar(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels, int sailingSpeed, unsigned numOfSails)
	: Boat(companyName, color, price, sailingSpeed, numOfSails), Car(companyName, color, price, drivingSpeed, numOfWheels)
{
}

SuperBoatCar::~SuperBoatCar()
{
}

SuperBoatCar& SuperBoatCar::operator=(const SuperBoatCar& other)
{
	return *this;
}

SuperBoatCar& SuperBoatCar::operator=(SuperBoatCar&& other) noexcept
{
	return *this;
}

void SuperBoatCar::raisePrice()
{
	price *= factorArr[eSuperBoatCar];
}

std::ostream& SuperBoatCar::print(std::ostream& out) const
{
	Vehicle::print(out);
	if (typeid(out) == typeid(std::ofstream))
	{
		out << drivingSpeed << " " << numOfWheels << " " << sailingSpeed << " " << numOfSails << std::endl;
	}
	else {
		out << "SuperBoatCar driving speed: " << drivingSpeed << ", number of wheels: " << numOfWheels << std::endl;
		out << "SuperBoatCar sailing speed: " << sailingSpeed << ", number of sails: " << numOfSails << std::endl;
		out << "Maxspeed of land and water: " << getSpeed() << ", Turbo speed: " << getMaxSpeed() << std::endl;
	}
	return out;
}

std::istream& SuperBoatCar::read(std::istream& in)
{
	Vehicle::read(in);
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> drivingSpeed >> numOfWheels >> sailingSpeed >> numOfSails;
	}
	else {
		std::cout << "Enter driving speed : ";
		in >> drivingSpeed;
		std::cout << "Enter number of wheels: ";
		in >> numOfWheels;
		std::cout << "Enter sailing speed : ";
		in >> sailingSpeed;
		std::cout << "Enter number of sails: ";
		in >> numOfSails;
	}
	return in;
}