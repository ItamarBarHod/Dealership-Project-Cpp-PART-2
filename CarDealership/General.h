#pragma once

#include <stdlib.h> // rand 
#include <time.h>

#include "DealershipFactory.h"
#include "DealershipManager.h"

#include "SuperBoatCar.h"
#include "Salesman.h"

using std::cout;
using std::cin;
using std::endl;

const char fileName[] = "Dealership.txt";
const unsigned int MAX_WORKER = 5;
const unsigned int MAX_VEC = 7;
const int BUFFER_SIZE = 100;

Vehicle::eColor getColor();
Salesman* createSalesmen();
Vehicle** createVehicles();

void mainMenu();

bool saveDealershipToFile(const VehicleDealership& dealership);
void exitDealership();

int getNumFromUser(const char* str, int min, int max);