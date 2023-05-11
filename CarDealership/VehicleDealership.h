#include "Building.h"
#include "Salesman.h"
#include "Vehicle.h"

#define MAX_DS_NAME 20

class VehicleDealership {
private:
	char name[MAX_DS_NAME];
	int monthlyProfit;
	Building hall;
	Salesman* salesmanArr;
	unsigned salesmanCount;
	Vehicle* vehicleArr; // size is hall->getCapacity;
	unsigned vehicleCount;
public:
	VehicleDealership(const char* name, Building& hall, int maxWorkers, int maxVehicles);
	VehicleDealership(const VehicleDealership& other) = delete;
	VehicleDealership(VehicleDealership&& other) = delete;
	~VehicleDealership();

	int getMonthlyProfit() const;
	bool addSalesman(Salesman& s); // monthly profit -= salesman salary
	bool buyVehicle(Vehicle& v); // monthlyprofit -= vehicle price
	// setting price by factor
	void showCollection() const; //using vehicle <<
	const Salesman& getRandomSalesman() const;
	Vehicle& findVehicle(int money) const; // check closest price
	void showIdenticalVehicles() const; // using vehicle ==
	void sellVehicle(const Vehicle& v); // check exist, add profit, remove from array
	void showFastestVehicle() const; // using vehicle > (speed compare)
	void showBestWorker() const; // using worker << and >=

};