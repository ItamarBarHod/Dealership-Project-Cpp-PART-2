#include "General.h"
#include "Vehicle.h"

Vehicle::Vehicle() : companyName(nullptr), color(Vehicle::eWhite), price(0)
{
}

Vehicle::Vehicle(std::ifstream& inFile) : companyName(nullptr), color(Vehicle::eWhite), price(0)
{
	inFile >> *this;
}

Vehicle::Vehicle(const char* companyName, eColor color, float price)
	: companyName(nullptr), color(color), price(price)
{
	if (companyName)
		this->companyName = _strdup(companyName);
}

Vehicle::Vehicle(const Vehicle& other) : companyName(nullptr)
{

}

Vehicle::Vehicle(Vehicle&& other) noexcept : companyName(nullptr)
{

}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{

	}
	return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
	// TODO: insert return statement here
}

Vehicle::~Vehicle()
{
	if (companyName)
		delete[] companyName;
}

bool Vehicle::operator>(const Vehicle& other)
{
	return (price > other.price);
}

bool Vehicle::operator==(const Vehicle& other)
{
	return (strcmp(companyName, other.companyName) == 0 && color == other.color && typeid(*this) == typeid(other));
}

bool Vehicle::setColor(const eColor color)
{
	if (color < 0 || color > eNofColor)
		return false;
	this->color = color;
	return true;
}

std::ostream& Vehicle::print(std::ostream& out) const
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << companyName << " " << color << " " << price << std::endl;
	}
	else {
		out << "\nPrinting vehicle:\n";
		out << "Company name: " << companyName << ", Color: " << colorArr[color] << ", Price: " << price << ", ";
	}
	return out;
}

std::istream& Vehicle::read(std::istream& in)
{
	char buffer[256];
	int tempColor;
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> buffer;
		companyName = _strdup(buffer);
		in >> tempColor >> price;
		color = (Vehicle::eColor)tempColor;
	}
	else {
		std::cout << "Enter company name (one word): ";
		in >> buffer;
		companyName = _strdup(buffer);
		std::cout << "Enter color: ";
		in >> tempColor;
		color = (Vehicle::eColor)tempColor;
		std::cout << "Enter price: ";
		in >> price;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Vehicle& v)
{
	return v.print(out);
}

std::istream& operator>>(std::istream& in, Vehicle& v)
{
	return v.read(in);
}