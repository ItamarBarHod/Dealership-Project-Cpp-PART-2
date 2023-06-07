#pragma once

#include "DealershipFactory.h"

class DealershipManager
{
public:
	virtual ~DealershipManager();
	static VehicleDealership* getInstance();
	static void addSalesman();
	static void addVehicle();
	static void releaseInstance();

private:
	static VehicleDealership* vecDealership;

	DealershipManager();
	DealershipManager(const DealershipManager& other) = delete;
	DealershipManager& operator=(const DealershipManager&) = delete;

};