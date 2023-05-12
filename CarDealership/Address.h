#include <iostream>

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
	const Address& operator=(Address&& other);
	~Address();


	friend std::istream& operator>>(std::istream& in, Address& date);
	const char* getCity() const;
	const char* getStreet() const;
	unsigned getHouseNum() const;

};