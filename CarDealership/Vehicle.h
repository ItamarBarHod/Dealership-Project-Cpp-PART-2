#pragma once
#include <iostream>

class Vehicle {
public:
	typedef enum { sfBoat, sfCar, sfSuperBoatCar, eNofSFactor } sellFactor;
	typedef enum { eWhite, eBlack, eBlue, eRed, eYellow, ePurple, eNofColor } COLOR;
	const float factorArr[eNofSFactor] = { 1.4, 1.3, 2 };
	const char* colorArr[eNofColor] = { "White", "Black", "Blue", "Red", "Yellow", "Purple" };
protected:
	const char* companyName;
	COLOR color;
	float price;
	const float sellFactor;

protected:
	virtual void toOs(std::ostream& out) const;

public:

	Vehicle(const char* companyName, COLOR color, float price);
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other);
	const Vehicle& operator=(const Vehicle& other);
	const Vehicle& operator=(Vehicle&& other);
	virtual ~Vehicle();

	virtual friend std::ostream& operator<<(std::ostream& out, const Vehicle& v);
	virtual bool operator>(const Vehicle& other) final;
	virtual bool operator==(const Vehicle& other) final;

	virtual float getPrice() const final;
	virtual const char* getColor() const final;
	bool setColor(COLOR color);
	virtual const char* getCompanyName() const final;
	virtual void setPrice() = 0;
	virtual int getSpeed() const = 0;
};
