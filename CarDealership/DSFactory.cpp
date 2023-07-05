#include "VehicleDealership.h"
#include "DSFactory.h"

Vehicle* const DSFactory::createVehicle(std::istream& in)
{
	int type;
	Vehicle* newVehicle = nullptr;
	if (typeid(in) == typeid(std::ifstream))
	{
		in >> type;
		newVehicle = DSFactory::createVehicleHelper(in, type);
	}
	else {
		VehicleDealership* vd = VehicleDealership::getInstance();
		if (vd->isMaxVehicles())
			throw "Maximum Vehicles, cannot add more";
		type = chooseVehicleType();
		newVehicle = DSFactory::createVehicleHelper(in, type);
	}
	return newVehicle;
}

Salesman* const DSFactory::createSalesman()
{
	VehicleDealership* vd = VehicleDealership::getInstance();
	if (vd->isMaxSalesman())
		throw "Maximum salesmen, cannot add more";
	return new Salesman(std::cin);
}

VehicleDealership* const DSFactory::createDealershipManually()
{
	try {
		char buffer[BUFFER_SIZE];
		std::cout << "Enter dealership name: ";
		std::cin.getline(buffer, BUFFER_SIZE);
		Building building(std::cin); // throws no vehicle space
		std::cout << "Enter max salesmen: ";
		int maxSalesmen;
		std::cin >> maxSalesmen;
		if (maxSalesmen < 1) // throws no salesmen
			throw "Cant initialize dealership without salesmen, please try again";
		std::cin.get();
		std::cout << "Initializing cleaner: " << std::endl;
		Cleaner cleaner = Cleaner(std::cin);
		return new VehicleDealership(buffer, building, maxSalesmen, cleaner);
	}
	catch (const char* msg) {
		throw msg;
	}
}

Vehicle* const DSFactory::createVehicleHelper(std::istream& in, int type)
{
	switch (type)
	{
	case Vehicle::eCar:
		return new Car(in);
	case Vehicle::eBoat:
		return new Boat(in);
	case Vehicle::eSuperBoatCar:
		return new SuperBoatCar(in);
	default:
		throw "Error: createVehicle type (should never print)";
	}
}