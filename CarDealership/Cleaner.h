#ifndef Cleaner_H
#define Cleaner_H
#pragma once

#include "Worker.h"
#include "Vehicle.h"

class Cleaner : public Worker {
private:
	int numOfCleanedVehicles;

private:
	std::ostream& print(std::ostream& out) const override;
	std::istream& read(std::istream& in) override;

public:
	Cleaner(std::istream& in);
	Cleaner(const char* name, Address** address, const Date& birthday, int salary, unsigned numOfAddresses, int maxSalesman, int salesmanCount);

	friend std::istream& operator>>(std::istream& in, Cleaner& cleaner);

	void cleanVehicle(Vehicle& vec); // changes both vec and members
};

#endif