#pragma once

#include <iostream>
#include "Building.h"
#include "Salesman.h"
#include "SuperBoatCar.h"

class VehicleDealership {
private:
	const static int DEALERSHIP_NAME_SIZE = 20;
private:
	char name[DEALERSHIP_NAME_SIZE];
	double monthlyProfit;
	Building place;
	Salesman* salesmanArr;
	int salesmanCount;
	int maxSalesman;
	Vehicle** vehicleArr;
	int vehicleCount;
	int maxVehicles;

private:
	VehicleDealership(const VehicleDealership& other) = delete;

public:
	VehicleDealership();
	VehicleDealership(std::istream& in);
	VehicleDealership(const char* name, const Building& place, int maxSalesman);
	~VehicleDealership();

	friend std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership);
	friend std::istream& operator>>(std::istream& in, VehicleDealership& dealership);

	double getMonthlyProfit() const { return monthlyProfit; }

	bool addVehicle(const Vehicle& vehicle);
	bool addSalesman(const Salesman& salesman);

	void showDealership() const;

	void sellCollection();
	void sellVehicle();

	Vehicle* hasIdenticalVehicles() const;

	const Vehicle* getBestVehicle() const;
	const Salesman* getBestWorker() const;

};