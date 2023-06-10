#pragma once

#include <iostream>
#include <fstream>

class Vehicle;
class Salesman;

const char fileName[] = "Dealership.txt";
const int BUFFER_SIZE = 100;

Salesman** createThreeSalesmen();
Vehicle** createSevenVehicles();

void mainMenu();

void printOptions();

void exitDealership();