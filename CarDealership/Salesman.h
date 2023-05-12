#pragma once

#include "Worker.h"

class Salesman : public Worker {
private:
	unsigned numOfDeals;
	double totalSales;
protected:
	virtual void toOs(std::ostream& out) const;
public:
	Salesman();
	Salesman(const char* name, Address& address, Date& birthday, int salary);
	double getAverageProfit() const; // totalSales / numOfDeals
	bool operator>=(const Salesman& other);
};