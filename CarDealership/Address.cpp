#include "Address.h"

Address::Address(std::istream& in) : houseNum(0)
{
	in >> *this;
}
Address::Address(const std::string& city, const std::string& street, unsigned houseNum) : city(city), street(street), houseNum(houseNum)
{
}

std::istream& operator>>(std::istream& in, Address& address)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		std::getline(in, address.city);
		std::getline(in, address.street);
		in >> address.houseNum;
		in.get();
	}
	else {
		std::cout << "Creating address!" << std::endl;
		std::cout << "Enter city: ";
		std::getline(in, address.city);
		std::cout << "Enter street: ";
		std::getline(in, address.street);
		std::cout << "Enter house number: ";
		in >> address.houseNum;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Address& address)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << address.city << std::endl;
		out << address.street << std::endl;
		out << address.houseNum << std::endl;
	}
	else {
		out << "Address: " << address.city << ", " << address.street << ", " << address.houseNum << std::endl;
	}
	return out;
}