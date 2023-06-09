#ifndef DEALERSHIPFACTORY_H
#define DEALERSHIPFACTORY_H
#pragma once 

#include "SuperBoatCar.h"
#include "Salesman.h"

class DealershipFactory
{
public:
	static int getTypeFromUser();
	static Vehicle* createVehicle(std::istream& in);
	static Salesman createSalesman();
};

#endif