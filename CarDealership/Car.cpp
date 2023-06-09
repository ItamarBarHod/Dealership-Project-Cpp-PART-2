#include "Car.h"

Car::Car(std::istream& in) : Vehicle(in)
{
	read(in);
}

Car::Car(const char* companyName, eColor color, float price, int drivingSpeed, unsigned numOfWheels) : Vehicle(companyName, color, price), drivingSpeed(drivingSpeed), numOfWheels(numOfWheels)
{
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
		out << "Car speed: " << drivingSpeed << ", number of wheels: " << numOfWheels << "\n\n";
	}
	return out;
}

std::istream& Car::read(std::istream& in)
{
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
