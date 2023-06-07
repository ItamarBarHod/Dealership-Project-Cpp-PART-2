#include "VehicleDealership.h"
#include "General.h"

int main()
{
	set_terminate(exitDealership);

	std::cout << "Welcome to the vehicle dealership" << std::endl;

	Salesman* worker;
	std::ifstream inFile(fileName);
	if (!inFile) {
		std::cout << "initalizing manually\n";
		worker = new Salesman(std::cin);
	}
	else {
		worker = new Salesman(inFile);
		std::cout << "\n\INITIALIZED FROM FILE!\n\n";
	}
	inFile.close();
	std::cout << *worker << std::endl;

	std::ofstream outFile(fileName);
	if (!outFile)
	{
		std::cout << "error saving to file\n";
	}
	outFile << *worker;
	outFile.close();

	int pause;
	std::cout << "pause\n";
	std::cin >> pause;

	/*VehicleDealership* dealership;
	try {
		dealership = DealershipManager::getInstance();
	}
	catch (std::bad_alloc& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		terminate();
	}
	catch (...) {
		terminate();
	}
	dealership->showDealership();*/

	//bool program = true;
	//int option;
	//try {
	//	do {
	//		//printOptions();
	//		cin >> option;
	//		switch (option)
	//		{
	//		case 1:
	//			dealership->showDealership();
	//			break;
	//		case 2:
	//			DealershipManager::addVehicle();
	//			break;
	//		case 3:
	//			DealershipManager::addSalesman();
	//			break;
	//		case 4:
	//			dealership->sellCollection();
	//			break;
	//		case 5:
	//			dealership->hasIdenticalVehicles();
	//			break;
	//		case 6:
	//			const Vehicle * tempVehicle = dealership->getBestVehicle();
	//			if(tempVehicle)
	//			std::cout << "The best vehicle is: " << *tempVehicle << std::endl;
	//			else {
	//			std::cout << "No vehicles exist yet\n";
	//			}
	//			break;
	//		case 7:
	//			const Salesman * tempWorker = dealership->getBestWorker();
	//			std::cout << "The best worker is: " << *tempWorker << std::endl;
	//			break;
	//		case 8:
	//			program = false;
	//			break;
	//		}
	//	} while (program);
	//}
	//catch (std::bad_alloc& e) {
	//	std::cout << e.what() << std::endl;
	//}
	//catch (...) {
	//	std::cout << "error in program" << std::endl;
	//}

	/*if (!saveDealershipToFile(*dealership))
		std::cout << "Couldnt save files";

	int pause;
	std::cin >> pause;

	DealershipManager::releaseInstance();*/
	//	srand((unsigned int)time(NULL));
	//	{
	//#define	TEST_WITH_INIT // use for faster testing
	//#ifdef TEST_WITH_INIT
	//		Address buildingAddress;
	//		cin >> buildingAddress;
	//#else
	//		Address buildingAddress("Tel-Aviv", "Afeka", 123);
// 
	//#endif
	//		Vehicle** vehicleArr = createVehicles();
	//		if (!vehicleArr)
	//			return -1;
	//		Salesman* workerArr = createSalesmen();
	//		if (!workerArr)
	//			return -1;
	//
	//		int vehicleCount = getNumFromUser("Vehicles", MAX_VEC);
	//		int workerCount = getNumFromUser("Salesmen", MAX_WORKER);
	//
	//		Building building(buildingAddress, vehicleCount, 6000);
	//		VehicleDealership dealership("Cars, boats & more", building, workerCount);
	//		{
	//			cout << "Monthly profit before workers + vehicles:" << endl;
	//			cout << dealership.getMonthlyProfit() << endl; // 1
	//
	//			cout << "--------------------------------------" << endl;
	//			if (!dealership.addRandomVehicles(vehicleArr))
	//				cout << "Error adding vehicles\n"; // 2
	//			if (!dealership.hireRandomSalesmen(workerArr)) // 3
	//				cout << "Error adding salesmen\n";
	//
	//			cout << "Monthly profit after adding workers + vehicles: ";
	//			cout << dealership.getMonthlyProfit() << endl; // 1
	//
	//			dealership.showDealership(); // 4
	//			cout << "--------------------------------------" << endl;
	//
	//			if (dealership.hasIdenticalVehicle()) { // 5
	//				cout << "The dealership has atleast 2 identical vehicles" << endl;
	//			}
	//			else {
	//				cout << "No 2 vehicles in the dealership are identical" << endl;
	//			}
	//			cout << "--------------------------------------" << endl;
	//
	//			cout << "The best vehicle in the dealership is:\n";
	//			const Vehicle* bestVehicle = dealership.getBestVehicle(); // 6
	//			if (!bestVehicle)
	//				return -1;
	//			cout << *bestVehicle << endl;
	//
	//			cout << "Selling collection!" << endl;
	//			dealership.sellCollection(); // 7
	//			cout << "Dealership total monthly profit:" << endl;
	//			cout << dealership.getMonthlyProfit() << endl;
	//			cout << "--------------------------------------" << endl;
	//
	//			dealership.showDealership();
	//			cout << "--------------------------------------" << endl;
	//			cout << "The best worker in the dealership is:\n";
	//			const Salesman* bestWorker = dealership.getBestWorker(); // 8
	//			cout << bestWorker << endl;
	//		}
	//
	//		for (int i = 0; i < vehicleCount; i++)
	//		{
	//			delete vehicleArr[i];
	//		}
	//		delete vehicleArr;
	//		delete workerArr;
	//	}
	//	cout << "Bye bye!" << endl;
	return 0;
}