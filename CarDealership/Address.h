#pragma once

#include "General.h"

class Address {
private:
	std::string city;
	std::string street;
	int houseNum;

public:
	Address(std::istream& in);

	friend std::istream& operator>>(std::istream& in, Address& address);
	friend std::ostream& operator<<(std::ostream& out, const Address& address);

	const std::string& getCity() const { return city; }
	const std::string& getStreet() const { return street; }
	int getHouseNum() const { return houseNum; }
};