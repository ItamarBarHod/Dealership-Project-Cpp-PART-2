#pragma once

#include "Building.h"
#include "Salesman.h"
#include "Vehicle.h"
#include "Car.h"
#include "Boat.h"
#include "SuperBoatCar.h"

#define MAX_DS_NAME 20

class VehicleDealership {
private:
	char name[MAX_DS_NAME];
	double monthlyProfit;
	Building& place;
	Salesman* salesmanArr;
	unsigned salesmanCount;
	unsigned maxSalesman;
	Vehicle* vehicleArr;
	unsigned vehicleCount;
	unsigned maxVehicles;
public:
	VehicleDealership(const char* name, Building& place, int maxWorkers);
	VehicleDealership(const VehicleDealership& other) = delete;
	VehicleDealership(VehicleDealership&& other) = delete;
	~VehicleDealership();

	double getMonthlyProfit() const;
	bool addRandomVehicles(Vehicle** vehicleArr);
	bool hireRandomSalesmen(const Salesman& workerArr);

	bool addSalesman(const Salesman& s);
	bool buyVehicle(const Vehicle& v);
	void showCollection() const;

	bool hasIdenticalVehicle() const;
	void sellCollection();
	void sellVehicle();
	const Vehicle* getBestVehicle() const;
	const Salesman& getBestWorker() const;

};