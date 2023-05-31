#include <stdlib.h> // rand 
#include <time.h>

#include "VehicleDealership.h"
#include "General.h"

int main()
{
	srand((unsigned int)time(NULL));
	{
#define	TEST_WITH_INIT // use for faster testing
#ifdef TEST_WITH_INIT
		Address buildingAddress;
		cin >> buildingAddress;
#else
		Address buildingAddress("Tel-Aviv", "Afeka", 123);
#endif
		Vehicle** vehicleArr = createVehicles();
		if (!vehicleArr)
			return -1;
		Salesman* workerArr = createSalesmen();
		if (!workerArr)
			return -1;

		int vehicleCount = getNumFromUser("Vehicles", MAX_VEC);
		int workerCount = getNumFromUser("Salesmen", MAX_WORKER);

		Building building(buildingAddress, vehicleCount, 6000);
		VehicleDealership dealership("Cars, boats & more", building, workerCount);
		{
			cout << "Monthly profit before workers + vehicles:" << endl;
			cout << dealership.getMonthlyProfit() << endl; // 1

			cout << "--------------------------------------" << endl;
			if (!dealership.addRandomVehicles(vehicleArr))
				cout << "Error adding vehicles\n"; // 2
			if (!dealership.hireRandomSalesmen(workerArr)) // 3
				cout << "Error adding salesmen\n";

			cout << "Monthly profit after adding workers + vehicles: ";
			cout << dealership.getMonthlyProfit() << endl; // 1

			dealership.showCollection(); // 4
			cout << "--------------------------------------" << endl;

			if (dealership.hasIdenticalVehicle()) { // 5
				cout << "The dealership has atleast 2 identical vehicles" << endl;
			}
			else {
				cout << "No 2 vehicles in the dealership are identical" << endl;
			}
			cout << "--------------------------------------" << endl;

			cout << "The best vehicle in the dealership is:\n";
			const Vehicle* bestVehicle = dealership.getBestVehicle(); // 6
			if (!bestVehicle)
				return -1;
			cout << *bestVehicle << endl;

			cout << "Selling collection!" << endl;
			dealership.sellCollection(); // 7
			cout << "Dealership total monthly profit:" << endl;
			cout << dealership.getMonthlyProfit() << endl;
			cout << "--------------------------------------" << endl;

			dealership.showCollection();
			cout << "--------------------------------------" << endl;
			cout << "The best worker in the dealership is:\n";
			const Salesman bestWorker = dealership.getBestWorker(); // 8
			cout << bestWorker << endl;
		}

		for (int i = 0; i < vehicleCount; i++)
		{
			delete vehicleArr[i];
		}
		delete vehicleArr;
		delete workerArr;
	}
	cout << "Bye bye!" << endl;
	return 0;
}