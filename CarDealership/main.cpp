#include <stdlib.h> // rand 
#include <time.h>

#include "VehicleDealership.h"

#define MAX_WORKERS 3
#define AVAILABLE_WORKERS 5

#define MAX_VEHICLES 5
#define AVAILABLE_VEHICLES 7

int main()
{
	srand(time(NULL));
	using std::cout;
	using std::cin;
	using std::endl;
	{
		Address buildingAddress = Address();
		cin >> buildingAddress;
		Address address1("Raanana", "Etrog", 5);
		Address address2("Kfar Saba", "Hadar", 66);
		Address address3("Natanya", "Rakefet", 10);
		Address address4("Tel-Aviv", "Kineret", 34);
		Address address5("Hod-Hasharon", "HaBanim", 30);

		Date bday1 = Date();
		Date bday2(1994, 3, 7);
		Date bday3(1996, 5, 6);
		Date bday4(1998, 4, 12);
		Date bday5(1991, 2, 9);

		Vehicle* vehicleArr[AVAILABLE_VEHICLES];
		vehicleArr[0] = new Car("Ferari", eBlue, 10000, 200, 4);
		vehicleArr[1] = new Boat("Skoda", eBlack, 5000, 200, 0);
		vehicleArr[2] = new Boat("Honda", eWhite, 20000, 200, 1);
		vehicleArr[3] = new SuperBoatCar("Honda", eWhite, 10000, 200, 4, 100, 2);
		vehicleArr[4] = new Car("Toyota", eWhite, 6000, 200, 4);
		vehicleArr[5] = new SuperBoatCar("Ferari", eBlue, 6500, 150, 2, 100, 0);
		vehicleArr[6] = new Car("Toyota", eYellow, 10000, 200, 3);

		Salesman workerArr[AVAILABLE_WORKERS];
		workerArr[0] = Salesman("Amit", address1, bday1, 2000);
		workerArr[1] = Salesman("Gilad", address2, bday2, 3000);
		workerArr[2] = Salesman("Asher", address3, bday3, 2500);
		workerArr[3] = Salesman("Lavy", address4, bday4, 3100);
		workerArr[4] = Salesman("Itamar", address5, bday5, 2900);

		Building building(buildingAddress, MAX_VEHICLES, 2500);
		VehicleDealership dealership("Cars, boats & more", building, MAX_WORKERS);
		{
			cout << dealership.getMonthlyProfit() << endl; // 1
			cout << "--------------------------------------" << endl;
			if (!dealership.addRandomVehicles(vehicleArr))
				cout << "Error adding vehicles\n"; // 2
			if (!dealership.hireRandomSalesmen(*workerArr)) // 3
				cout << "Error adding salesmen\n";

			dealership.showCollection(); // 4
			cout << "--------------------------------------" << endl;

			if (dealership.hasIdenticalVehicle()) { // 5
				cout << "The dealership has atleast 2 identical vehicles" << endl;
			}
			else {
				cout << "No 2 vehicles in the dealership are identical" << endl;
			}
			cout << "--------------------------------------" << endl;

			cout << "The fastest vehicle in the dealership is:\n";
			const Vehicle* bestVehicle = dealership.getFastestVehicle(); // 6
			cout << *bestVehicle << endl;

			cout << "Selling collection!" << endl;
			dealership.sellCollection(); // 7
			cout << "Dealership total monthly profit:" << endl;
			cout << dealership.getMonthlyProfit() << endl;
			cout << "--------------------------------------" << endl;

			dealership.showCollection();
			cout << "--------------------------------------" << endl;
			cout << "The best worker in the dealership is:\n";
			dealership.showBestWorker(); // 8
		}

		for (int i = 0; i < AVAILABLE_VEHICLES; i++)
		{
			delete vehicleArr[i];
		}
	}
	cout << "Bye bye!" << endl;
	return 0;
}