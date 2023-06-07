#include "DealershipFactory.h"
#include "SuperBoatCar.h"

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
