#pragma once
#include <iostream>

class Vehicle {
public:
	typedef enum { eBoat, eCar, eSuperBoatCar, eNofSFactor } eVehicle;
	typedef enum { eWhite, eBlack, eBlue, eRed, eYellow, ePurple, eNofColor } eColor;
	const float factorArr[eNofSFactor] = { 1.4F, 1.3F, 2.0F };
	const char* colorArr[eNofColor] = { "White", "Black", "Blue", "Red", "Yellow", "Purple" };

protected:
	const char* companyName;
	eColor color;
	float price;
	const float sellFactor;

protected:
	virtual std::ostream& toOs(std::ostream& out) const;
	virtual void setPrice() = 0;

public:

	Vehicle(const char* companyName, eColor color, float price);
	Vehicle(const Vehicle& other) = delete;
	Vehicle& operator = (const Vehicle& other) = delete;
	virtual ~Vehicle();

	virtual bool operator>(const Vehicle& other) final;
	virtual bool operator==(const Vehicle& other) final;
	friend std::ostream& operator<<(std::ostream& out, const Vehicle& v);

	virtual float getPrice() const final { return price; }
	virtual const char* getColor() const final { return colorArr[color]; }
	virtual const char* getCompanyName() const final { return companyName; }
	bool setColor(const eColor color);
	virtual int getSpeed() const = 0;
	virtual eVehicle getType() const = 0;
};


std::ostream& operator<<(std::ostream& out, const Vehicle& v)
{
	v.toOs(out);
	return out;
}