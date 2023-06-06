#include "General.h"

Vehicle::eColor getColor()
{
	int color;
	std::cout << "enter color between 0 and " << Vehicle::eNofColor << std::endl;
	do {
		std::cin >> color;
	} while (color < 0 || color > Vehicle::eNofColor);
	return (Vehicle::eColor)color;
}

int getNumFromUser(const char* str, int min, int max)
{
	int num = 0;
	cout << "Enter " << str << endl;
	do {
		cin >> num;
		if (num < min || num > max)
			cout << "Error: please enter a number between " << min << " and " << max;
	} while (num < min || num > max);
	return num;
}


Salesman* createSalesmen()
{
	Salesman* workerArr = new Salesman[MAX_WORKER];

	Address address1("Raanana", "Etrog", 5);
	Address address2("Kfar Saba", "Hadar", 66);
	Address address3("Natanya", "Rakefet", 10);
	Address address4("Tel-Aviv", "Kineret", 34);
	Address address5("Hod-Hasharon", "HaBanim", 30);
	Address twoAddress[2];
	twoAddress[0] = Address(address4);
	twoAddress[1] = Address(address5);

	Date bday1(1995, 7, 27);
	Date bday2(1994, 9, 17);
	Date bday3(1996, 5, 6);
	Date bday4(1998, 4, 12);
	Date bday5(1991, 2, 9);

	workerArr[0] = Salesman("Amit", &address1, bday1, 2000, 1);
	workerArr[1] = Salesman("Gilad", &address2, bday2, 3000, 1);
	workerArr[2] = Salesman("Asher", &address3, bday3, 2500, 1);
	workerArr[3] = Salesman("Lavy", nullptr, bday4, 3100, 0);
	workerArr[4] = Salesman("Itamar", twoAddress, bday5, 2900, 2);

	return workerArr;
}

Vehicle** createVehicles()
{
	Vehicle** vehicleArr = new Vehicle * [MAX_VEC];

	vehicleArr[0] = new Car("Ferari", Vehicle::eBlue, 10000, 200, 4);
	vehicleArr[1] = new Boat("Skoda", Vehicle::eBlack, 5000, 310, 0);
	vehicleArr[2] = new Boat("Honda", Vehicle::eWhite, 20000, 200, 1);
	vehicleArr[3] = new SuperBoatCar("Honda", Vehicle::eWhite, 10000, 200, 4, 100, 2);
	vehicleArr[4] = new Car("Toyota", Vehicle::eWhite, 6000, 220, 4);
	vehicleArr[5] = new SuperBoatCar("Ferari", Vehicle::eBlue, 6500, 150, 2, 100, 0);
	vehicleArr[6] = new Car("Toyota", Vehicle::eYellow, 10000, 120, 3);

	return vehicleArr;
}

void mainMenu()
{
}

bool saveDealershipToFile(const VehicleDealership& dealership)
{
	std::ofstream outFile(fileName);
	if (outFile)
	{
		outFile << dealership;
		outFile.close();
		return true;
	}
	return false;
}

void exitDealership()
{
	std::cout << "Fatal error in dealership, exiting program" << std::endl;
	exit(1);
}
