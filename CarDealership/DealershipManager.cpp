#include "DealershipManager.h"

VehicleDealership* DealershipManager::vecDealership = nullptr;

DealershipManager::~DealershipManager()
{
}

VehicleDealership* DealershipManager::getInstance()
{
	if (!vecDealership) {
		try {
			std::ifstream inFile(fileName);
			if (!inFile) {
				vecDealership = new VehicleDealership(std::cin);
			}
			else {
				vecDealership = new VehicleDealership(inFile);
				inFile.close();
			}
		}
		catch (std::bad_alloc& e) {
			throw;
		}
		catch (...) {
			throw;
		}
	}
	return vecDealership;
}

void DealershipManager::addSalesman()
{
}

void DealershipManager::addVehicle()
{
}

void DealershipManager::releaseInstance()
{
	if (vecDealership)
		delete vecDealership;
}
