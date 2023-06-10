#include "Vehicle.h"

const float Vehicle::CLEAN_FACTOR = 1.1F;

Vehicle::Vehicle(std::istream& in)
{
	read(in);
}

Vehicle::Vehicle(const Vehicle& other) : companyName(nullptr), color(other.color), price(other.price), isClean(other.isClean)
{
	if (other.companyName)
		companyName = _strdup(other.companyName);
}

Vehicle::Vehicle(Vehicle&& other) noexcept : companyName(nullptr), color(other.color), price(other.price), isClean(other.isClean)
{
	std::swap(companyName, other.companyName);
}

Vehicle::Vehicle(const char* companyName, eColor color, float price) : companyName(nullptr), color(color), price(price), isClean(false)
{
	if (companyName)
		this->companyName = _strdup(companyName);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		if (other.companyName)
			companyName = _strdup(other.companyName);
		color = other.color;
		price = other.price;
		isClean = other.isClean;
	}
	return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
	if (this != &other)
	{
		if (other.companyName)
			std::swap(companyName, other.companyName);
		color = other.color;
		price = other.price;
		isClean = other.isClean;
	}
	return *this;
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

void Vehicle::operator++()
{
	price *= CLEAN_FACTOR;
	isClean = true;
}

void Vehicle::printManufacturer() const
{
	std::cout << "Available manufacturers:" << std::endl;
	for (int i = 0; i < eNofManufacturer; i++)
	{
		std::cout << i << ": " << manufacturerArr[i] << std::endl;
	}
}

void Vehicle::printColors() const
{
	std::cout << "Available colors:" << std::endl;
	for (int i = 0; i < eNofColor; i++)
	{
		std::cout << i << ": " << colorArr[i] << std::endl;
	}
}

int Vehicle::chooseCompany() const
{
	int temp = 0;
	do
	{
		printManufacturer();
		std::cin >> temp;
	} while (temp < 0 || temp >= eNofManufacturer);
	return temp;
}

Vehicle::eColor Vehicle::chooseColor() const
{
	int temp;
	do
	{
		printColors();
		std::cin >> temp;
	} while (temp < 0 || temp >= eNofColor);
	return (eColor)temp;
}

std::ostream& Vehicle::print(std::ostream& out) const
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << companyName << " " << color << " " << price << " " << isClean << std::endl;
	}
	else {
		out << "\nCompany name: " << companyName << ", Color: " << colorArr[color] << ", Price: " << price
			<< ", is clean: " << std::boolalpha << isClean << std::endl;
		//boolalpha - prints true false instead of 0/1
	}
	return out;
}

std::istream& Vehicle::read(std::istream& in)
{
	char buffer[BUFFER_SIZE];
	int temp;
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> buffer;
		companyName = _strdup(buffer);
		in >> temp >> price;
		color = (Vehicle::eColor)temp;
		in >> isClean;
	}
	else {
		isClean = false;
		std::cout << "Choose company name" << std::endl;
		companyName = _strdup(manufacturerArr[chooseCompany()]);
		std::cout << "Enter color" << std::endl;
		color = chooseColor();
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