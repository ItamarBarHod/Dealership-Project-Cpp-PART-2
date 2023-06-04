#include "Address.h"


Address::Address() : city(nullptr), street(nullptr)
{
}
Address::Address(const char* city, const char* street, unsigned houseNum) : houseNum(houseNum)
{
	setCity(city);
	setStreet(street);
}
Address::Address(const Address& other)
{
	*this = other;
}
Address::Address(Address&& other) : houseNum(other.houseNum)
{
	std::swap(city, other.city);
	std::swap(street, other.street);
}
const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		setCity(city);
		setStreet(street);
		houseNum = other.houseNum;
	}
	return *this;
}
const Address& Address::operator=(Address&& other)
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
	delete[] city;
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

