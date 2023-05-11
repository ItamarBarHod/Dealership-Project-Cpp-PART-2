#pragma once

typedef enum { sfBoat, sfCar, sfSuperBoatCar, eNofSFactor } sellFactor;
typedef enum { eWhite, eBlack, eBlue, eRed, eNofColor } COLOR;
const static char* colorArr[eNofColor] = { "white", "black", "blue", "red" };
const static float factorArr[eNofSFactor] = { 1.2, 1.3, 1.5 };