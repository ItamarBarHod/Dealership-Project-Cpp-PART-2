#pragma once

#include <iostream>
#include <fstream>

class Address {
private:
	char* city;
	char* street;
	unsigned houseNum;

public:
	Address();
	Address(const char* city, const char* street, unsigned houseNum);
	Address(const Address& other);
	Address(Address&& other);
	const Address& operator=(const Address& other);
	const Address& operator=(Address&& other) noexcept;
	~Address();


	friend std::istream& operator>>(std::istream& in, Address& address);
	friend std::ostream& operator<<(std::ostream& out, const Address& address);

	void setStreet(const char* street);
	void setCity(const char* street);
	const char* getCity() const { return city; }
	const char* getStreet() const { return street; }
	unsigned getHouseNum() const { return houseNum; }

};

std::istream& operator>>(std::istream& in, Address& address)
{
	char buffer[100];
	if (typeid(in) == typeid(std::ifstream))
	{
		char delimiter;
		in >> buffer >> delimiter;
		address.city = _strdup(buffer);
		in >> buffer >> delimiter >> address.houseNum;
		address.street = _strdup(buffer);
	}
	else {
		in.getline(buffer, 100);
		address.city = _strdup(buffer);
		in.getline(buffer, 100);
		address.street = _strdup(buffer);
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
		out << "City: " << address.city << "Street: " << address.street << "House Number: " << address.houseNum << std::endl;
	}
	return out;
}