#include "VehicleManager.h"

VehicleDealership* VecManager::getInstance()
{
	if (!VecDealership)
		return new VehicleDealership();
	return VecDealership;
}