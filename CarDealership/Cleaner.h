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
	Cleaner(const std::string& name, const LinkedList<Address*>& address, const Date& birthday, int salary);

	friend std::istream& operator>>(std::istream& in, Cleaner& cleaner);

	void cleanVehicle(Vehicle& vec); // non const
};