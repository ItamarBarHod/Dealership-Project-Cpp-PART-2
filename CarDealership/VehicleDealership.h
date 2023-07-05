#pragma once

#include "Building.h"
#include "Cleaner.h"

class VehicleSorter;

class VehicleDealership {
public:
	static VehicleDealership* getInstance();
	static void releaseInstance();

private:
	static VehicleDealership* vecDealership;

	VehicleDealership(std::istream& in);
	VehicleDealership(const VehicleDealership& other) = delete;
	void setSortStrategy(int strategy);

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
	VehicleSorter* vSorter;

public:
	VehicleDealership(const char* name, const Building& place, int maxSalesman, const Cleaner& cleaner);
	virtual ~VehicleDealership();

	friend std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership);
	friend std::istream& operator>>(std::istream& in, VehicleDealership& dealership);

	double getMonthlyProfit() const { return monthlyProfit; }
	int getVehicleCount() const { return vehicleCount; }
	int getSalesmanCount() const { return salesmanCount; }
	Cleaner& getCleaner() { return cleaner; } // non const
	const VehicleSorter& getVehicleSorter() const { return *vSorter; }
	const Vehicle& getBestVehicle() const;
	const Salesman& getBestSalesman() const;
	Vehicle& getVehicle(int index) const; // non const return
	Salesman& getSalesman(int index) const; // non const return

	void addVehicle(Vehicle* const vehicle); // const address
	void addSalesman(Salesman* const salesman);

	void printDealership() const;
	void printVehicles() const;
	void printSalesmen() const;

	void sellAllCollectionRandomly();
	void sellVehicle(int salesmanIndex, int vehicleIndex);

	void sortVehicles(int strategy);
	bool isMaxSalesman() const { return salesmanCount == maxSalesman; }
	bool isMaxVehicles() const { return vehicleCount == maxVehicles; }
};