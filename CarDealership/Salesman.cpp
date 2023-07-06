#include "Salesman.h"

Salesman::Salesman(std::istream& in) : Worker(in), numOfDeals(0), totalSales(0)
{
	read(in);
}

Salesman::Salesman(const std::string& name, const LinkedList<Address*>& address, const Date& birthday, int salary, unsigned numOfDeals, double totalSales) : Worker(name, address, birthday, salary), numOfDeals(numOfDeals), totalSales(totalSales)
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
