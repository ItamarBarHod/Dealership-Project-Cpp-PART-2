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
	Vehicle* vehicleArr; // size is place->getCapacity;
	unsigned vehicleCount;
	unsigned maxVehicles;
public:
	VehicleDealership(const char* name, Building& place, int maxWorkers);
	VehicleDealership(const VehicleDealership& other) = delete;
	VehicleDealership(VehicleDealership&& other) = delete;
	~VehicleDealership();

	double getMonthlyProfit() const;
	bool addRandomVehicles(const Vehicle** vehicleArr);
	bool hireRandomSalesmen(const Salesman& workerArr);

	bool addSalesman(const Salesman& s); // monthly profit -= salesman salary
	bool buyVehicle(const Vehicle& v); // monthlyprofit -= vehicle price
	// setting price by factor
	void showCollection() const; //using vehicle <<

	bool hasIdenticalVehicle() const; // using vehicle ==
	void sellCollection(); // using sellvehicle
	void sellVehicle(); // monthly profit += vehicle price after factor, delete vehicle from array
	const Vehicle* getBestVehicle() const; // using vehicle > (price compare)
	const Salesman& getBestWorker() const; // using worker << and >=

};