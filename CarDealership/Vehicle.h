#pragma once
#include <iostream>

class Vehicle {
public:
	typedef enum { sfBoat, sfCar, sfSuperBoatCar, eNofSFactor } sellFactor;
	typedef enum { eWhite, eBlack, eBlue, eRed, eYellow, ePurple, eNofColor } COLOR;
	const float factorArr[eNofSFactor] = { 1.4F, 1.3F, 2.0F };
	const char* colorArr[eNofColor] = { "White", "Black", "Blue", "Red", "Yellow", "Purple" };
protected:
	const char* companyName;
	COLOR color;
	float price;
	const float sellFactor;

protected:
	virtual void toOs(std::ostream& out) const;
	virtual void setPrice() = 0;

public:

	Vehicle(const char* companyName, COLOR color, float price);
	Vehicle(const Vehicle& other) = delete;
	Vehicle& operator = (const Vehicle& other) = delete;
	virtual ~Vehicle();

	friend std::ostream& operator<<(std::ostream& out, const Vehicle& v);
	virtual bool operator>(const Vehicle& other) final;
	virtual bool operator==(const Vehicle& other) final;

	virtual float getPrice() const final;
	virtual const char* getColor() const final;
	bool setColor(COLOR color);
	virtual const char* getCompanyName() const final;
	virtual int getSpeed() const = 0;
};
