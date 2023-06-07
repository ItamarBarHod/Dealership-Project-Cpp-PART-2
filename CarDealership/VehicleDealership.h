#pragma once

#include <iostream>
#include "Building.h"
#include "Salesman.h"
#include "SuperBoatCar.h"

#define MAX_DS_NAME 20

class VehicleDealership {
private:
	char name[MAX_DS_NAME];
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
	VehicleDealership(VehicleDealership&& other) = delete;
	void sellVehicle();

public:
	VehicleDealership();
	VehicleDealership(std::istream& in);
	VehicleDealership(const char* name, const Building& place, int maxSalesman) throw(char*, std::bad_alloc&);
	~VehicleDealership();

	friend std::istream& operator>>(std::istream& in, VehicleDealership& dealership);
	friend std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership);

	double getMonthlyProfit() const { return monthlyProfit; }

	bool addVehicle(const Vehicle& vehicle);
	bool addSalesman(const Salesman& salesman);

	void showDealership() const;

	void sellCollection();

	Vehicle* hasIdenticalVehicles() const;

	const Vehicle* getBestVehicle() const;
	const Salesman* getBestWorker() const;

};