#include "VehicleDealership.h"

class VecManager
{
	static VehicleDealership* getInstance();
private:
	VecManager();
	VecManager(const VecManager& other);
	VecManager& operator=(const VecManager&) = delete;


	static VehicleDealership* VecDealership;

};