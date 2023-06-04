#include "Salesman.h"

Salesman::Salesman(const char* name, const Address* address, Date& birthday, int salary, unsigned numOfAddresses)
	: Worker(name, address, birthday, salary, numOfAddresses), totalSales(0), numOfDeals(0)
{
}

std::ostream& Salesman::print(std::ostream& out) const
{
	Worker::print(out);
	out << "Num of deals: " << numOfDeals << std::endl;
	out << "Total sales: " << totalSales << std::endl;
	out << "Average profit" << getAverageProfit() << std::endl;
	return out;
}

const double Salesman::getAverageProfit() const
{
	if (numOfDeals == 0)
		return 0;
	return totalSales / numOfDeals;
}