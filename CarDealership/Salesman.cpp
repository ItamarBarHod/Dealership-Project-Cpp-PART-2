#include "Salesman.h"

Salesman::Salesman(std::istream& in) : Worker(in), numOfDeals(0), totalSales(0)
{
	read(in);
}

Salesman::Salesman(const Salesman& other) : Worker(other), numOfDeals(other.numOfDeals), totalSales(other.totalSales)
{
}

Salesman::Salesman(Salesman&& other) noexcept : Worker(std::move(other)), numOfDeals(other.numOfDeals), totalSales(other.totalSales)
{
}

Salesman& Salesman::operator=(const Salesman& other)
{
	if (this != &other)
	{
		Worker::operator=(other);
		numOfDeals = other.numOfDeals;
		totalSales = other.totalSales;
	}
	return *this;
}

Salesman& Salesman::operator=(Salesman&& other) noexcept
{
	if (this != &other)
	{
		Worker::operator=(std::move(other));
		numOfDeals = other.numOfDeals;
		totalSales = other.totalSales;
	}
	return *this;
}

Salesman::Salesman(const char* name, Address** address, const Date& birthday, int salary, unsigned numOfAddresses, unsigned numOfDeals, double totalSales) : Worker(name, address, birthday, salary, numOfAddresses), numOfDeals(numOfDeals), totalSales(totalSales)
{
}

Salesman::~Salesman()
{
}

void Salesman::printSalesman() const
{
	Worker::print(std::cout);
	const double profit = getAverageProfit();
	std::cout << "Num of deals: " << numOfDeals << std::endl;
	std::cout << "Total sales: " << totalSales << std::endl;
	std::cout << "Average profit: " << profit << std::endl;
}

void Salesman::doSell(const Vehicle& vehicle)
{
	totalSales += vehicle.getPrice();
	numOfDeals++;
}

std::ostream& Salesman::print(std::ostream& out) const
{
	Worker::print(out);
	const double profit = getAverageProfit();
	if (typeid(out) == typeid(std::ofstream))
	{
		out << numOfDeals << " " << totalSales << std::endl;
	}
	else {
		std::cout << "Num of deals: " << numOfDeals << std::endl;
		std::cout << "Total sales: " << totalSales << std::endl;
		std::cout << "Average profit: " << profit << std::endl;
	}
	return out;
}

std::istream& Salesman::read(std::istream& in)
{
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> numOfDeals >> totalSales;
	}
	return in;
}

const double Salesman::getAverageProfit() const
{
	if (numOfDeals == 0)
		return 0;
	return totalSales / numOfDeals;
}

std::istream& operator>>(std::istream& in, Salesman& salesman)
{
	return salesman.read(in);
}
