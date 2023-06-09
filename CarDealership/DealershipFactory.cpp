#include "DealershipFactory.h"
#include "VehicleDealership.h"

int DealershipFactory::getTypeFromUser()
{
	return 0;
}

Vehicle* DealershipFactory::createVehicle(std::istream& in)
{
	Vehicle* newVehicle = nullptr;
	int type;
	in >> type;
	switch (type)
	{
	case Vehicle::eCar:
		newVehicle = new Car(in);
		break;
	case Vehicle::eBoat:
		newVehicle = new Boat(in);
		break;
	case Vehicle::eSuperBoatCar:
		newVehicle = new SuperBoatCar(in);
		break;
	}
	return newVehicle;
}

Salesman DealershipFactory::createSalesman()
{
	VehicleDealership* vd = VehicleDealership::getInstance();
	if (vd->isMaxSalesman())
		throw "Maximum salesmen, cannot add more";
	return Salesman(std::cin);
}
