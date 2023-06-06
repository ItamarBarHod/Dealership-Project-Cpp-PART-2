#include "VehicleDealership.h"

VehicleDealership::VehicleDealership()
{
}

VehicleDealership::VehicleDealership(std::ifstream& inFile)
{
	inFile >> *this;
}

VehicleDealership::VehicleDealership(const char* name, const Building& place, int maxSalesman) noexcept(false)
	: place(place), maxSalesman(maxSalesman), salesmanArr(nullptr), vehicleArr(nullptr),
	salesmanCount(0), vehicleCount(0), monthlyProfit(0)
{
	if (name)
		strcpy_s(this->name, name);
	else {
		this->name[0] = 0;
	}
	monthlyProfit -= place.getCost();
	maxVehicles = place.getCapacity();

	try {
		vehicleArr = new Vehicle * [maxVehicles];
		salesmanArr = new Salesman[maxSalesman];
	}
	catch (std::bad_alloc& e) {
		// no need to delete name
		throw;
	}
	catch (...) {
		throw;
	}
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

bool VehicleDealership::addVehicle(const Vehicle& vehicle)
{
	if (vehicleCount == maxVehicles)
		return false;
	vehicleArr[vehicleCount] = vehicle.Clone();
	vehicleCount++;
	monthlyProfit -= vehicle.getPrice();
	vehicleArr[vehicleCount]->raisePrice();
	return true;
}

bool VehicleDealership::addSalesman(const Salesman& salesman)
{
	if (salesmanCount == maxSalesman)
		return false;
	salesmanArr[salesmanCount] = Salesman(salesman);
	salesmanCount++;
	monthlyProfit -= salesman.getSalary();
	return true;
}

void VehicleDealership::showDealership() const
{
	std::cout << "Dealership name: " << name << " | " << place
		<< "Monthly profit: " << monthlyProfit << "\n\n";
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

Vehicle* VehicleDealership::hasIdenticalVehicles() const
{
	if (vehicleCount == 0)
		return false;
	Vehicle* temp = nullptr;
	for (int i = 0; i < vehicleCount; i++)
	{
		Vehicle* temp = vehicleArr[0];
		for (int j = i + 1; j < vehicleCount; j++)
		{
			if (*temp == *vehicleArr[j])
				return temp;
		}
	}
	return temp;
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

std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << dealership.name << std::endl;
		out << dealership.place << std::endl;
		out << dealership.monthlyProfit << dealership.maxSalesman << dealership.salesmanCount << std::endl;
		for (int i = 0; i < dealership.salesmanCount; i++)
		{
			out << dealership.salesmanArr[i];
		}
		out << dealership.maxVehicles << dealership.vehicleCount << std::endl;
		for (int i = 0; i < dealership.vehicleCount; i++)
		{
			out << *dealership.vehicleArr[i];
		}
	}
	else {
		dealership.showDealership();
	}
	return out;
}

std::ifstream& operator>>(std::ifstream& in, VehicleDealership& dealership)
{
	in >> dealership.name >> dealership.place >> dealership.monthlyProfit;
	in >> dealership.maxSalesman >> dealership.salesmanCount;
	dealership.salesmanArr = new Salesman[dealership.maxSalesman];
	for (int i = 0; i < dealership.salesmanCount; i++)
	{
		in >> dealership.salesmanArr[i];
	}
	in >> dealership.maxVehicles >> dealership.vehicleCount;
	dealership.vehicleArr = new Vehicle * [dealership.maxVehicles];
	for (int i = 0; i < dealership.vehicleCount; i++)
	{
		in >> *dealership.vehicleArr[i];
	}
	return in;
}
