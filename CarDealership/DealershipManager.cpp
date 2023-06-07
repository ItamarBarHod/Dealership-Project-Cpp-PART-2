#include "DealershipManager.h"

VehicleDealership* DealershipManager::vecDealership = nullptr;

DealershipManager::~DealershipManager()
{
}

VehicleDealership* DealershipManager::getInstance() throw(std::bad_alloc&)
{
	if (!vecDealership) {
		try {
			std::ifstream inFile(fileName);
			if (!inFile) {
				DealershipFactory::initDealership(vecDealership);
			}
			else {
				vecDealership = new VehicleDealership(inFile);
			}
			inFile.close();
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

void DealershipManager::releaseInstance()
{
	if (vecDealership)
		delete vecDealership;
}
