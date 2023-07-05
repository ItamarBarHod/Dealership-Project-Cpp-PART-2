#pragma once

#include <iostream>
#include <fstream>

class Vehicle;
class Salesman;

static const char fileName[] = "Dealership.txt";
static const int BUFFER_SIZE = 100;

bool mainMenu(int option);

void printOptions();
void printVehicleTypes();
int chooseVehicleType();
int getVehicleIndexFromUser();
int getSalesmanIndexFromUser();
int getCleanIndexFromUser();

void terminateDealership();