#include "VehicleDealership.h"
#include "General.h"

int main()
{
	set_terminate(exitDealership);

	std::cout << "Welcome to the vehicle dealership" << std::endl;
	VehicleDealership* dealership = VehicleDealership::getInstance();

	std::cin.get();
	std::cout << *dealership;
	try {
		dealership->addSalesman(DealershipFactory::createSalesman());
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}

	try {
		if (dealership->isMaxVehicles())
			throw "max vehicles";
		const Vehicle* newVehicle = DealershipFactory::createVehicle(std::cin);
		dealership->addVehicle(*newVehicle);
		delete newVehicle;
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}
	std::cout << "here bol!";

	/*std::ifstream inFile(fileName);
	if (!inFile) {
		std::cout << "initalizing manually\n";
		worker = new Salesman(std::cin);
	}
	else {
		worker = new Salesman(inFile);
		std::cout << "\n\nINITIALIZED FROM FILE!\n\n";
	}
	inFile.close();
	std::cout << *worker << std::endl;

	std::ofstream outFile(fileName);
	if (!outFile)
	{
		std::cout << "error saving to file\n";
	}
	outFile << *worker;
	outFile.close();*/

	std::cout << "here" << std::endl;

	/*bool program = true;
	int option;
	do {
		try {
			printOptions();
			std::cin >> option;
			switch (option)
			{
			case 1:
				dealership->printDealership();
				break;
			case 2:
				DealershipCleaner::addVehicle();
				break;
			case 3:
				DealershipCleaner::addSalesman();
				break;
			case 4:
				dealership->sellCollection();
				break;
			case 5:
				dealership->hasIdenticalVehicles();
				break;
			case 6:
				const Vehicle * tempVehicle = dealership->getBestVehicle();
				if (tempVehicle)
					std::cout << "The best vehicle is: " << *tempVehicle << std::endl;
				else {
					std::cout << "No vehicles exist yet\n";
				}
				break;
			case 7:
				const Salesman * tempWorker = dealership->getBestWorker();
				std::cout << "The best worker is: " << *tempWorker << std::endl;
				break;
			case 8:
				program = false;
				break;
			}
		}
		catch (const char* msg) {
			std::cout << msg << std::endl;
		}
		catch (...) {
			std::cout << "error in program" << std::endl;
		}
	} while (program);*/
	std::cin.get(); // pause

	VehicleDealership::releaseInstance();

	return 0;
}