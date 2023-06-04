#pragma once

#include "Worker.h"

class Date;

class Salesman : public Worker {
private:
	unsigned numOfDeals;
	double totalSales;

protected:
	std::ostream& print(std::ostream& out) const;

public:
	Salesman();
	Salesman(const char* name, const Address* address, Date& birthday, int salary, unsigned numOfAddresses);

	const double getAverageProfit() const;
	bool operator>=(const Salesman& other) const { return getAverageProfit() >= other.getAverageProfit(); }
};