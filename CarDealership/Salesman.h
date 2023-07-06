#pragma once

#include "Worker.h"
#include "Vehicle.h"

class Salesman : public Worker {
private:
	unsigned numOfDeals;
	double totalSales;

private:
	std::ostream& print(std::ostream& out) const override;
	std::istream& read(std::istream& in) override;

public:
	Salesman(std::istream& in);
	Salesman(const std::string& name, const LinkedList<Address*>& address, const Date& birthday, int salary, unsigned numOfDeals, double totalSales);

	void printSalesman() const;
	void doSell(const Vehicle& vehicle);

	friend std::istream& operator>>(std::istream& in, Salesman& salesman);

	const double getAverageProfit() const;
	bool operator>=(const Salesman& other) const { return getAverageProfit() >= other.getAverageProfit(); }
};