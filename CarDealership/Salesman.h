#pragma once

#include "Worker.h"

class Salesman : public Worker {
private:
	unsigned numOfDeals;
	double totalSales;

protected:
	std::ostream& print(std::ostream& out) const;

public:
	Salesman();
	Salesman(std::istream& in);
	Salesman(const Salesman& other);
	Salesman(Salesman&& other) noexcept;
	Salesman& operator=(const Salesman& other);
	Salesman& operator=(Salesman&& other) noexcept;
	Salesman(const char* name, const Address* address, Date& birthday, int salary, unsigned numOfAddresses);

	friend std::istream& operator>>(std::istream& in, Salesman& salesman);

	const double getAverageProfit() const;
	bool operator>=(const Salesman& other) const { return getAverageProfit() >= other.getAverageProfit(); }
};