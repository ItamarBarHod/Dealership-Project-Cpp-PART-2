#pragma once

#include <iostream>
#include <fstream>

#include "DealershipFactory.h"
#include "Building.h"
#include "Cleaner.h"

class VehicleDealership {
public:
	static VehicleDealership* getInstance();
	static void releaseInstance();

private:
	static VehicleDealership* vecDealership;
	static VehicleDealership* createDealership();

	VehicleDealership(std::istream& in);
	VehicleDealership(const char* name, const Building& place, int maxSalesman, const Cleaner& cleaner);
	VehicleDealership(const VehicleDealership& other) = delete;

	std::istream& read(std::istream& in);
private:
	const char* name;
	double monthlyProfit;
	Building place;
	Cleaner cleaner;
	Salesman** salesmanArr;
	int salesmanCount;
	int maxSalesman;
	Vehicle** vehicleArr;
	int vehicleCount;
	int maxVehicles;

public:
	virtual ~VehicleDealership();

	friend std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership);
	friend std::istream& operator>>(std::istream& in, VehicleDealership& dealership);

	double getMonthlyProfit() const { return monthlyProfit; }
	int getVehicleCount() const { return vehicleCount; }
	int getSalesmanCount() const { return salesmanCount; }
	Cleaner& getCleaner() { return cleaner; } // non const
	const Vehicle& getBestVehicle() const;
	const Salesman& getBestSalesman() const;
	Vehicle& getVehicle(int index);


	void addVehicle(const Vehicle& vehicle);
	void addSalesman(const Salesman& salesman);

	void printDealership() const;
	void printVehicles() const;
	void printSalesmen() const;

	void sellCollection();
	void sellVehicle();

	Vehicle* hasIdenticalVehicles() const;
	bool isMaxSalesman() const { return salesmanCount == maxSalesman; }
	bool isMaxVehicles() const { return vehicleCount == maxVehicles; }



};