#include "VehicleDealership.h"

VehicleDealership* VehicleDealership::vecDealership = nullptr;

VehicleDealership::VehicleDealership(std::istream& in) : place(in), cleaner(in), name(nullptr), maxSalesman(0), salesmanArr(nullptr), vehicleArr(nullptr), salesmanCount(0), vehicleCount(0), monthlyProfit(0)
{ //building and cleaner require initlist
	read(in);
}

VehicleDealership::VehicleDealership(const char* name, const Building& place, int maxSalesman, const Cleaner& cleaner)
	: place(place), maxSalesman(maxSalesman), salesmanArr(nullptr), vehicleArr(nullptr),
	salesmanCount(0), vehicleCount(0), monthlyProfit(0), name(nullptr), cleaner(cleaner)
{
	if (name)
		this->name = _strdup(name);
	else
		this->name = "Default Dealership";

	monthlyProfit -= place.getCost();
	monthlyProfit -= cleaner.getSalary();
	maxVehicles = place.getCapacity();

	vehicleArr = new Vehicle * [maxVehicles];
	salesmanArr = new Salesman * [maxSalesman];
}

VehicleDealership* VehicleDealership::getInstance()
{
	if (!vecDealership) {
		std::ifstream inFile(fileName);
		if (!inFile) {
			vecDealership = createDealership();
		}
		else {
			vecDealership = new VehicleDealership(inFile);
			inFile.close();
		}
	}
	return vecDealership;
}

void VehicleDealership::releaseInstance()
{
	if (vecDealership) {
		std::ofstream outFile(fileName);
		if (outFile)
		{
			outFile << *vecDealership;
			outFile.close();
		}
		delete vecDealership;
	}
}

VehicleDealership* VehicleDealership::createDealership()
{
	char buffer[BUFFER_SIZE];
	std::cout << "Enter dealership name: ";
	std::cin.getline(buffer, BUFFER_SIZE);
	Building building(std::cin);
	std::cout << "Enter max workers: ";
	int maxWorkers;
	std::cin >> maxWorkers;
	std::cin.get();
	std::cout << "Initializing cleaner: " << std::endl;
	Cleaner cleaner = Cleaner(std::cin);
	return new VehicleDealership(buffer, building, maxWorkers, cleaner);
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
			delete salesmanArr[i];
		}
		delete[] salesmanArr;
	}
}

bool VehicleDealership::addVehicle(const Vehicle& vehicle)
{
	if (vehicleCount == maxVehicles)
		throw "Maximum amount of vehicles";
	vehicleArr[vehicleCount] = vehicle.Clone();
	monthlyProfit -= vehicle.getPrice();
	vehicleArr[vehicleCount]->raisePrice();
	vehicleCount++;
	return true;
}

bool VehicleDealership::addSalesman(const Salesman& salesman)
{
	if (salesmanCount == maxSalesman)
		throw "Maximum amount of salesmen";
	salesmanArr[salesmanCount] = new Salesman(salesman);
	salesmanCount++;
	monthlyProfit -= salesman.getSalary();
	return true;
}

void VehicleDealership::showDealership() const
{
	std::cout << "\n\nDealership name: " << name << " | " << place
		<< "Monthly profit: " << monthlyProfit << ", The cleaner is: \n\n" << cleaner << "\n\n";
	if (salesmanCount > 0)
	{
		std::cout << "There are " << salesmanCount << " salesmen\n\n";
		for (int i = 0; i < salesmanCount; i++)
		{
			std::cout << "Salesman number " << i + 1 << ": " << *salesmanArr[i] << std::endl;
		}
	}
	else {
		std::cout << "No salesmen exist" << std::endl;
	}
	if (vehicleCount > 0)
	{
		std::cout << "There are " << vehicleCount << " vehicles\n\n";
		for (int i = 0; i < vehicleCount; i++)
		{
			std::cout << "Vehicle number " << i + 1 << ": " << *vehicleArr[i] << std::endl;
		}
	}
	else {
		std::cout << "No vehicles exist" << std::endl;
	}
}

Vehicle* VehicleDealership::hasIdenticalVehicles() const
{
	if (vehicleCount == 0)
		return nullptr;
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
	Salesman* temp = salesmanArr[0];
	for (int i = 1; i < salesmanCount; i++)
	{
		if (*salesmanArr[i] >= *temp)
			temp = salesmanArr[i];
	}
	return temp;
}

std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		out << dealership.place << std::endl;
		out << dealership.cleaner << std::endl;
		out << dealership.name << std::endl;
		out << dealership.monthlyProfit << " " << dealership.maxSalesman << " "
			<< dealership.salesmanCount << std::endl;
		for (int i = 0; i < dealership.salesmanCount; i++)
		{
			out << *dealership.salesmanArr[i];
		}
		out << dealership.maxVehicles << " " << dealership.vehicleCount << std::endl;
		for (int i = 0; i < dealership.vehicleCount; i++)
		{
			out << dealership.vehicleArr[i]->getType() << " ";
			out << *dealership.vehicleArr[i];
		}
	}
	else {
		dealership.showDealership();
	}
	return out;
}

std::istream& VehicleDealership::read(std::istream& in)
{
	char buffer[BUFFER_SIZE];
	in.get();
	in.getline(buffer, BUFFER_SIZE);
	name = _strdup(buffer);
	in >> monthlyProfit;
	in >> maxSalesman >> salesmanCount;
	salesmanArr = new Salesman * [maxSalesman];
	if (maxSalesman >= salesmanCount) {
		for (int i = 0; i < salesmanCount; i++)
		{
			salesmanArr[i] = new Salesman(in);
		}
	}
	in >> maxVehicles >> vehicleCount;
	vehicleArr = new Vehicle * [maxVehicles];
	if (maxVehicles >= vehicleCount) {
		for (int i = 0; i < vehicleCount; i++)
		{
			vehicleArr[i] = DealershipFactory::createVehicle(in);
		}
	}
	return in;
}

std::istream& operator>>(std::istream& in, VehicleDealership& dealership)
{
	return dealership.read(in);
}
