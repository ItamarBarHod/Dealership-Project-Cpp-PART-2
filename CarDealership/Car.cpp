#include "Car.h"

Car::Car() : drivingSpeed(0), numOfWheels(0)
{
}

Car::Car(std::istream& in) : Vehicle(in)
{
	in >> *this;
}

Car::Car(const Car& other) : Vehicle(other)
{
}

Car::Car(Car&& other) noexcept
{
}


Car::Car(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels)
	: Vehicle(companyName, color, price), drivingSpeed(drivingSpeed), numOfWheels(numOfWheels)
{
}

Car::~Car()
{
}

Car& Car::operator=(const Car& other)
{
	// TODO: insert return statement here
}

Car& Car::operator=(Car&& other) noexcept
{
	// TODO: insert return statement here
}

void Car::raisePrice()
{
	price *= factorArr[eCar];
}


std::ostream& Car::print(std::ostream& out) const
{
	Vehicle::print(out);
	if (typeid(out) == typeid(std::ofstream))
	{
		out << drivingSpeed << " " << numOfWheels << std::endl;
	}
	else {
		out << "Car speed: " << drivingSpeed << ", number of wheels: " << numOfWheels << std::endl;
	}
	return out;
}

std::istream& Car::read(std::istream& in)
{
	Vehicle::read(in);
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> drivingSpeed >> numOfWheels;
	}
	else {
		std::cout << "Enter driving speed : ";
		in >> drivingSpeed;
		std::cout << "Enter number of wheels: ";
		in >> numOfWheels;
	}
	return in;
}
