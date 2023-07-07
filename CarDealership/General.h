#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Vehicle;
class Salesman;

const std::string fileName = "Dealership.txt";

bool mainMenu(int option);

void printOptions();
void printVehicleTypes();
int chooseVehicleType();
int getVehicleIndexFromUser();
int getSalesmanIndexFromUser();
int getCleanIndexFromUser();

void terminateDealership();