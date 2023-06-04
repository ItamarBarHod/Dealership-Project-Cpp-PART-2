#include "Address.h"




Address::Address()
{

}
Address::Address(const char* city, const char* street, unsigned houseNum)
{
	this->city = _strdup(city);
	this->street = _strdup(street);
}
Address::Address(const Address& other)
{

}
Address::Address(Address&& other)
{

}
const Address& Address::operator=(const Address& other)
{

}
const Address& Address::operator=(Address&& other)
{

}
Address::~Address()
{

}


const char* Address::getCity() const;
const char* Address::getStreet() const;
unsigned Address::getHouseNum() const;