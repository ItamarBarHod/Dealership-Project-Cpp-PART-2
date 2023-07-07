#pragma once

#include <vector>
#include "Building.h"
#include "Cleaner.h"
#include "LinkedList.h"

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
	std::string name;
	double monthlyProfit;
	Building place;
	Cleaner cleaner;
	std::vector<Salesman*> salesmanArr;
	std::vector<Vehicle*> vehicleArr;
	VehicleSorter* vSorter;

public:
	VehicleDealership(const std::string& name, const Building& place, const Cleaner& cleaner);
	virtual ~VehicleDealership();

	friend std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership);

	void printDealership() const;
	void printVehicles() const;
	void printSalesmen() const;

	double getMonthlyProfit() const { return monthlyProfit; }
	int getVehicleCount() const { return (int)vehicleArr.size(); }
	int getSalesmanCount() const { return (int)salesmanArr.size(); }
	Cleaner& getCleaner() { return cleaner; } // non const
	const VehicleSorter& getVehicleSorter() const { return *vSorter; }
	const Vehicle& getBestVehicle() const;
	const Salesman& getBestSalesman() const;
	Vehicle& getVehicle(int index) const; // non const return
	Salesman& getSalesman(int index) const; // non const return
	bool isMaxVehicles() const { return vehicleArr.size() == place.getCapacity(); }

	void addVehicle(Vehicle* const vehicle); // const address
	void addSalesman(Salesman* const salesman);

	void sellAllCollectionRandomly();
	void sellVehicle(int salesmanIndex, int vehicleIndex);

	void sortVehicles(int strategy);
};