#pragma once

#include "Worker.h"

class Salesman : public Worker {
private:
	unsigned numOfDeals;
	double totalSales;
public:
	Salesman();
	Salesman(const char* name, const Address* address, Date& birthday, int salary, unsigned numOfAddresses);

	friend virtual std::ostream& operator<<(std::ostream& out, const Salesman& Salesman);
	double getAverageProfit() const; // totalSales / numOfDeals
	bool operator>=(const Salesman& other);
};