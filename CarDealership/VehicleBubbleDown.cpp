#include "VehicleBubbleDown.h"

void VehicleBubbleDown::sortVehicles(std::vector<Vehicle*>& vehicleArr) const
{
	int size = (int)vehicleArr.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*vehicleArr[j] < *vehicleArr[j + 1])
				std::swap(vehicleArr[j], vehicleArr[j + 1]);
		}
	}
}

VehicleBubbleDown::VehicleBubbleDown(sortType type) : VehicleSorter(type)
{
}
