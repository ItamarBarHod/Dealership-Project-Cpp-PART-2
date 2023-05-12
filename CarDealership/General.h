#pragma once
#include "VehicleDealership.h"

void hireRandomWorkers(VehicleDealership& dealership, Salesman* workerArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int random = rand() % size;
		if (!dealership.addSalesman(workerArr[random]))
			throw "Error initializing workers";
	}
}

void buyRandomVehicles(VehicleDealership& dealership, Vehicle** vehicleArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int random = rand() % size;
		if (!dealership.buyVehicle(*vehicleArr[random]))
			throw "Error initializing vehicles";
	}
}

