#pragma once

#include "General.h"

class Address {
private:
	std::string city;
	std::string street;
	unsigned houseNum;

public:
	Address(std::istream& in);
	Address(const std::string& city, const std::string& street, unsigned houseNum);

	friend std::istream& operator>>(std::istream& in, Address& address);
	friend std::ostream& operator<<(std::ostream& out, const Address& address);

	const std::string& getCity() const { return city; }
	const std::string& getStreet() const { return street; }
	unsigned getHouseNum() const { return houseNum; }
};