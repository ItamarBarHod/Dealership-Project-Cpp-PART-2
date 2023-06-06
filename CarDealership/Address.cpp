#include "Address.h"

Address::Address() : city(nullptr), street(nullptr), houseNum(0)
{
}
Address::Address(std::ifstream& inFile) : city(nullptr), street(nullptr), houseNum(0)
{
	inFile >> *this;
}
Address::Address(const char* city, const char* street, unsigned houseNum) : houseNum(houseNum)
{
	setCity(city);
	setStreet(street);
}
Address::Address(const Address& other) : street(nullptr), city(nullptr)
{
	*this = other;
}
Address::Address(Address&& other) noexcept : city(nullptr), street(nullptr)
{
	std::swap(city, other.city);
	std::swap(street, other.street);
	houseNum = other.houseNum;
}
const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		setCity(other.city);
		setStreet(other.street);
		houseNum = other.houseNum;
	}
	return *this;
}
const Address& Address::operator=(Address&& other) noexcept
{
	if (this != &other)
	{
		std::swap(city, other.city);
		std::swap(street, other.street);
		houseNum = other.houseNum;
	}
	return *this;
}
Address::~Address()
{
	if (city)
		delete[] city;
	if (street)
		delete[] street;
}

void Address::setStreet(const char* str)
{
	if (street)
		delete[] street;
	street = nullptr;
	if (str)
		street = _strdup(str);
}


void Address::setCity(const char* str)
{
	if (city)
		delete[] city;
	city = nullptr;
	if (str)
		city = _strdup(str);
}

std::istream& operator>>(std::istream& in, Address& address)
{
	char buffer[256];
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> buffer;
		address.city = _strdup(buffer);
		in >> buffer >> address.houseNum;
		address.street = _strdup(buffer);
	}
	else {
		std::cout << "Enter city: ";
		in >> buffer;
		address.city = _strdup(buffer);
		std::cout << "Enter street: ";
		in >> buffer;
		address.street = _strdup(buffer);
		std::cout << "Enter house number: ";
		in >> address.houseNum;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Address& address)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << address.city << " " << address.street << " " << address.houseNum << std::endl;
	}
	else {
		out << "Address: " << address.city << ", " << address.street << ", " << address.houseNum << std::endl;
	}
	return out;
}