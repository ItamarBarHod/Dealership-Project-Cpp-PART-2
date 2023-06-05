#include "VehicleDealership.h"

VehicleDealership::VehicleDealership(const char* name, const Building& place, int maxSalesman)
	: place(place), maxSalesman(maxSalesman), salesmanArr(nullptr), vehicleArr(nullptr),
	salesmanCount(0), vehicleCount(0), monthlyProfit(0)
{
	if (name)
		strcpy(this->name, name);
	else {
		this->name[0] = 0;
	}
	maxVehicles = place.getCapacity();
	vehicleArr = new Vehicle * [maxVehicles];
	salesmanArr = new Salesman[maxSalesman];
}
VehicleDealership::~VehicleDealership()
{
	if (vehicleArr)
	{
		for (int i = 0; i < vehicleCount; i++)
		{
			delete vehicleArr[i];
		}
		delete[] vehicleArr;
	}
	if (salesmanArr)
	{
		for (int i = 0; i < salesmanCount; i++)
		{
			delete& salesmanArr[i];
		}
	}

}

double VehicleDealership::getMonthlyProfit() const
{
	return 0.0;
}

bool VehicleDealership::addRandomVehicles(Vehicle** vehicleArr)
{

}
bool VehicleDealership::hireRandomSalesmen(const Salesman* workerArr)
{

}

bool VehicleDealership::addSalesman(const Salesman& s)
{
	if (salesmanCount == maxSalesman)
		return false;
	salesmanArr[salesmanCount] = s;
	salesmanCount++;
	return true;

}
bool VehicleDealership::buyVehicle(const Vehicle* v)
{
	return false;
}
bool VehicleDealership::buyVehicle(const Vehicle* v)
{
	if (vehicleCount == maxVehicles)
		return false;
	vehicleArr[vehicleCount] = createVehicle(v);
	vehicleCount++;
	return true;
}

void VehicleDealership::showDealership() const
{
	std::cout << "Dealership name: " << name << "\nplace: " << place
		<< "\nMonthly profit: " << monthlyProfit << "\n\n";
	if (salesmanCount > 0)
	{
		std::cout << "There are " << salesmanCount << "salesmen" << std::endl;
		for (int i = 0; i < salesmanCount; i++)
		{
			std::cout << salesmanArr[i] << std::endl;
		}
	}
	else {
		std::cout << "No salesmen exist" << std::endl;
	}
	if (vehicleCount > 0)
	{
		std::cout << "There are " << vehicleCount << "vehicles" << std::endl;
		for (int i = 0; i < vehicleCount; i++)
		{
			std::cout << *vehicleArr[i] << std::endl;
		}
	}
	else {
		std::cout << "No vehicles exist" << std::endl;
	}
}

bool VehicleDealership::hasIdenticalVehicle() const
{
	if (vehicleCount == 0)
		return false;
	for (int i = 0; i < vehicleCount; i++)
	{
		Vehicle* temp = vehicleArr[0];
		for (int j = i + 1; j < vehicleCount; j++)
		{
			if (*temp == *vehicleArr[j])
				return true;
		}
	}
	return false;
}
void VehicleDealership::sellCollection()
{

}
void VehicleDealership::sellVehicle()
{

}
const Vehicle* VehicleDealership::getBestVehicle() const
{
	if (vehicleCount == 0)
		return nullptr;
	Vehicle* temp = vehicleArr[0];
	for (int i = 1; i < vehicleCount; i++)
	{
		if (vehicleArr[i] > temp)
			temp = vehicleArr[i];
	}
	return temp;
}
const Salesman* VehicleDealership::getBestWorker() const
{
	if (salesmanCount == 0)
		return nullptr;
	Salesman* temp = &salesmanArr[0];
	for (int i = 1; i < salesmanCount; i++)
	{
		if (salesmanArr[i] >= *temp)
			temp = &salesmanArr[i];
	}
	return temp;
}