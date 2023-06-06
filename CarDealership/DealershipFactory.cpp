#include "DealershipFactory.h"
#include "SuperBoatCar.h"

void DealershipFactory::initDealership(VehicleDealership* dealership)
{
	try {
		char name[100];
		std::cout << "Enter dealership name (one word): ";
		std::cin >> name;
		Building building;
		std::cin >> building;
		std::cout << "Enter max salesmen: ";
		int maxSalesmen;
		std::cin >> maxSalesmen;
		dealership = new VehicleDealership(name, building, maxSalesmen);
	}
	catch (std::bad_alloc& e) {
		throw;
	}
}

Vehicle* DealershipFactory::createVehicle(int type)
{
	Vehicle* newVehicle = nullptr;
	switch (type)
	{
	case Vehicle::eCar:
		newVehicle = new Car();
		std::cin >> *newVehicle;
		break;
	case Vehicle::eBoat:
		newVehicle = new Boat();
		std::cin >> *newVehicle;
		break;
	case Vehicle::eSuperBoatCar:
		newVehicle = new SuperBoatCar();
		std::cin >> *newVehicle;
		break;
	}
	return newVehicle;
}

Salesman* DealershipFactory::createSalesman() //throw(std::bad_alloc)
{
	Salesman* newSalesman = new Salesman();
	std::cin >> *newSalesman;
	return newSalesman;
}
