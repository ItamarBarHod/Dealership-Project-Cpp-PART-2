#ifndef SALESMAN_H
#define SALESMAN_H
#pragma once

#include "Worker.h"

class Salesman : public Worker {
private:
	unsigned numOfDeals;
	double totalSales;

private:
	std::ostream& print(std::ostream& out) const override;
	std::istream& read(std::istream& in) override;

public:
	Salesman(std::istream& in);
	Salesman(const Salesman& other);
	Salesman(Salesman&& other) noexcept;
	Salesman& operator=(const Salesman& other);
	Salesman& operator=(Salesman&& other) noexcept;
	Salesman(const char* name, Address** address, const Date& birthday, int salary, unsigned numOfAddresses, unsigned numOfDeals, double totalSales);
	~Salesman();

	friend std::istream& operator>>(std::istream& in, Salesman& salesman);

	const double getAverageProfit() const;
	bool operator>=(const Salesman& other) const { return getAverageProfit() >= other.getAverageProfit(); }
};

#endif