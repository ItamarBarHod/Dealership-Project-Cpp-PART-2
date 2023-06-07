#include "Salesman.h"

Salesman::Salesman() : numOfDeals(0), totalSales(0)
{
}

Salesman::Salesman(std::istream& in) : numOfDeals(0), totalSales(0)
{
	in >> *this;
}

Salesman::Salesman(const char* name, const Address* address, Date& birthday, int salary, unsigned numOfAddresses)
	: Worker(name, address, birthday, salary, numOfAddresses), totalSales(0), numOfDeals(0)
{
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

std::ostream& Salesman::print(std::ostream& out) const
{
	Worker::print(out);
	const double profit = getAverageProfit();
	if (typeid(out) == typeid(std::ofstream))
	{
		out << numOfDeals << " " << totalSales << std::endl;
	}
	else {
		out << "Num of deals: " << numOfDeals << std::endl;
		out << "Total sales: " << totalSales << std::endl;
		out << "Average profit: " << profit << std::endl;
	}
	return out;
}

const double Salesman::getAverageProfit() const
{
	if (numOfDeals == 0)
		return 0;
	return totalSales / numOfDeals;
}

std::istream& operator>>(std::istream& in, Salesman& salesman)
{
	in >> (Worker&)salesman;
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> salesman.numOfDeals >> salesman.totalSales;
	}
	else {
		std::cout << "Enter num of deals: ";
		in >> salesman.numOfDeals;
		std::cout << "Enter total sales: ";
		in >> salesman.totalSales;
		in.ignore();
	}
	return in;
}
