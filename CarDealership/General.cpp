#include "General.h"

#include "SuperBoatCar.h"
#include "Address.h"
#include "Date.h"
#include "Salesman.h"

Salesman** createFiveSalesmen()
{
	const int maxWorkers = 5;
	Salesman** workerArr = new Salesman * [maxWorkers];

	Address* address1 = new Address("Raanana", "Etrog", 5);
	Address* address2 = new Address("Kfar Saba", "Hadar", 66);
	Address* address3 = new Address("Natanya", "Rakefet", 10);
	Address* address4 = new Address("Tel-Aviv", "Kineret", 34);
	Address* address5 = new Address("Hod-Hasharon", "HaBanim", 30);
	Address* twoAddress[2];
	twoAddress[0] = new Address(*address4);
	twoAddress[1] = new Address(*address5);

	Date bday1(1995, 7, 27);
	Date bday2(1994, 9, 17);
	Date bday3(1996, 5, 6);
	Date bday4(1998, 4, 12);
	Date bday5(1991, 2, 9);

	workerArr[0] = new Salesman("Amit", &address1, bday1, 2000, 1, 25000, 2);
	workerArr[1] = new Salesman("Gilad", &address2, bday2, 3000, 1, 45000, 2);
	workerArr[2] = new Salesman("Asher", &address3, bday3, 2500, 1, 70000, 3);
	workerArr[3] = new Salesman("Lavy", nullptr, bday4, 3100, 0, 0, 0);
	workerArr[4] = new Salesman("Itamar", twoAddress, bday5, 2900, 2, 25000, 1);

	return workerArr;
}

Vehicle** createSevenVehicles()
{
	const int MAX_VEHICLES = 7;
	Vehicle** vehicleArr = new Vehicle * [MAX_VEHICLES];

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

void printOptions()
{
	std::cout << "options" << std::endl;
}

void exitDealership()
{
	std::cout << "Fatal error in dealership, exiting program" << std::endl;
	exit(1);
}
