#include "VehicleDealership.h"
#include "DSFactory.h"
#include "VehicleBubbleDown.h"
#include "VehicleBubbleUp.h"

VehicleDealership* VehicleDealership::vecDealership = nullptr;

VehicleDealership::VehicleDealership(std::istream& in) : place(in), cleaner(in), monthlyProfit(0), vSorter(nullptr)
{ //building and cleaner require initlist
	read(in);
}

void VehicleDealership::setSortStrategy(int strategy)
{
	if (strategy < 0 || strategy > 1)
		throw std::out_of_range("No such sort available");
	delete vSorter;
	VehicleSorter::sortType type = (VehicleSorter::sortType)strategy;
	if (strategy == (int)VehicleSorter::eBubbleDown)
		vSorter = new VehicleBubbleDown(type);
	else
		vSorter = new VehicleBubbleUp(type);
}

VehicleDealership::VehicleDealership(const std::string& name, const Building& place, const Cleaner& cleaner)
	: name(name), place(place), monthlyProfit(0), cleaner(cleaner),
	vSorter(new VehicleBubbleDown(VehicleSorter::eBubbleDown))
{
	monthlyProfit -= place.getCost();
	monthlyProfit -= cleaner.getSalary();
}

VehicleDealership* VehicleDealership::getInstance()
{
	if (!vecDealership) {
		std::ifstream inFile(fileName);
		if (!inFile) {
			vecDealership = DSFactory::createDealershipManually();
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

VehicleDealership::~VehicleDealership()
{
	for (int i = 0; i < vehicleArr.size(); i++)
	{
		delete vehicleArr[i];
	}
	for (int i = 0; i < salesmanArr.size(); i++)
	{
		delete salesmanArr[i];
	}
	delete vSorter;
}

void VehicleDealership::addVehicle(Vehicle* const vehicle)
{
	vehicle->raisePrice();
	vehicleArr.push_back(vehicle);
	monthlyProfit -= vehicle->getPrice();
}

void VehicleDealership::addSalesman(Salesman* const salesman)
{
	salesmanArr.push_back(salesman);
	monthlyProfit -= salesman->getSalary();
}

void VehicleDealership::printDealership() const
{
	std::cout << "\n\nDealership name: " << name << " | " << place
		<< "Monthly profit: " << monthlyProfit << "\nSorting vehicle strategy is: " << vSorter->getStrategyName()
		<< "\nThe cleaner is: \n\n" << cleaner << std::endl;;
	try {
		printSalesmen();
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << "\n" << std::endl;
	}
	printVehicles();
}

void VehicleDealership::printSalesmen() const
{
	if (salesmanArr.empty())
		throw std::out_of_range("No salesmen exist yet");

	std::cout << "There are " << salesmanArr.size() << " salesmen\n\n";
	int i = 1;
	for (auto& salesman : salesmanArr)
	{
		std::cout << "Salesman number " << i++ << ": " << *salesman << std::endl;
	}
}

void VehicleDealership::printVehicles() const
{
	if (vehicleArr.empty())
		throw std::invalid_argument("No vehicles exist yet");

	std::cout << "There are " << vehicleArr.size() << " vehicles\n\n";
	int i = 1;
	for (auto& vehicle : vehicleArr)
	{
		std::cout << "Vehicle number " << i++ << ": " << vehicle << std::endl;
	}
}

void VehicleDealership::sellAllCollectionRandomly()
{
	if (salesmanArr.empty())
		throw std::invalid_argument("No salesman available to sell collection");
	if (vehicleArr.empty())
		throw std::invalid_argument("No vehicles available to sell");

	int position = 0, printNumber = 1;
	for (auto& vehicle : vehicleArr)
	{
		int randomSalesmanIndex = rand() % salesmanArr.size();
		const Salesman& salesman = *salesmanArr[randomSalesmanIndex];
		std::cout << "Salesman " << salesman.getName() << " sold vehicle number: "
			<< printNumber++ << " for " << vehicle->getPrice() << " dollars" << std::endl;
		sellVehicle(randomSalesmanIndex, position);
		position++;
	}
}

void VehicleDealership::sellVehicle(int salesmanIndex, int vehicleIndex)
{
	if (salesmanIndex < 0 || salesmanIndex >= salesmanArr.size())
		throw std::out_of_range("Invalid salesman number");
	if (vehicleIndex < 0 || vehicleIndex >= vehicleArr.size())
		throw std::out_of_range("Invalid Vehicle number");

	const Vehicle& vehicle = getVehicle(vehicleIndex);
	Salesman& salesman = getSalesman(salesmanIndex);
	salesman.doSell(vehicle);
	monthlyProfit += vehicle.getPrice();

	delete vehicleArr[vehicleIndex];
}

void VehicleDealership::sortVehicles(int strategy)
{
	setSortStrategy(strategy);
	vSorter->sortVehicles(vehicleArr);
}

Vehicle& VehicleDealership::getVehicle(int index) const
{
	if (index < 0 || index >= vehicleArr.size())
		throw std::out_of_range("No such vehicle index");
	return *vehicleArr[index];
}

Salesman& VehicleDealership::getSalesman(int index) const
{
	return *salesmanArr[index];
}

const Vehicle& VehicleDealership::getBestVehicle() const
{
	if (vehicleArr.empty())
		throw std::invalid_argument("There are no vehicles yet");

	const Vehicle* temp = vehicleArr.front();
	for (auto& vehicle : vehicleArr)
	{
		if (*vehicle > *temp)
			temp = vehicle;
	}
	return *temp;
}

const Salesman& VehicleDealership::getBestSalesman() const
{
	if (salesmanArr.empty())
		throw std::invalid_argument("There are no salesmen yet");
	const Salesman* temp = salesmanArr.front();
	for (auto& salesman : salesmanArr)
	{
		if (*salesman >= *temp)
			temp = salesman;
	}
	return *temp;
}

std::ostream& operator<<(std::ostream& out, const VehicleDealership& dealership)
{
	if (typeid(out) == typeid(std::ofstream))
	{
		int vehicleSize = (int)dealership.vehicleArr.size();
		out << dealership.place << std::endl;
		out << dealership.cleaner << std::endl;
		out << dealership.name << std::endl;
		out << dealership.monthlyProfit << " " << dealership.salesmanArr.size() << " " << std::endl;
		for (auto& salesman : dealership.salesmanArr)
		{
			out << *salesman;
		}
		out << dealership.vehicleArr.size() << std::endl;
		for (auto& vehicle : dealership.vehicleArr)
		{
			out << *vehicle;
		}
		out << (int)dealership.vSorter->getType();
	}
	else {
		dealership.printDealership();
	}
	return out;
}

std::istream& VehicleDealership::read(std::istream& in)
{
	int salesmanCount, vehicleCount;
	in.get();
	std::getline(in, name);
	in >> monthlyProfit;
	in >> salesmanCount;
	salesmanArr.reserve(salesmanCount);
	for (int i = 0; i < salesmanCount; i++)
	{
		salesmanArr.push_back(new Salesman(in));
	}
	in >> vehicleCount;
	for (int i = 0; i < vehicleCount; i++)
	{
		vehicleArr.push_back(DSFactory::createVehicle(in));
	}
	int strategy;
	in >> strategy;
	setSortStrategy(strategy);
	return in;
}

std::istream& operator>>(std::istream& in, VehicleDealership& dealership)
{
	return dealership.read(in);
}