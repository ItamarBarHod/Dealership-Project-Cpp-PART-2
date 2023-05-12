#include "VehicleDealership.h"

#define MAX_WORKERS 5
#define MAX_VEHICLES 3

int main()
{
	{
		Building building("Hod hasharon", "Ramataim", 123, MAX_VEHICLES, 2500);
		VehicleDealership dealership("Cars, boats & more", building, MAX_WORKERS);
		{
			// code
		}
	}
	return 0;
}