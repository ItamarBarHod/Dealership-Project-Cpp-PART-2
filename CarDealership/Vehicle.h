#pragma once

#include <iostream>
#include <fstream>

class Vehicle {
public:
	typedef enum { eCar, eBoat, eSuperBoatCar, eNofVehicle } eVehicle;
	typedef enum { eWhite, eBlack, eBlue, eRed, eYellow, ePurple, eNofColor } eColor;
	const float factorArr[eNofVehicle] = { 1.4F, 1.3F, 2.0F };
	const char* colorArr[eNofColor] = { "White", "Black", "Blue", "Red", "Yellow", "Purple" };

protected:
	const char* companyName;
	eColor color;
	float price;

protected:
	virtual std::ostream& print(std::ostream& out) const;
	virtual std::istream& read(std::istream& in);
	virtual int getSpeed() const = 0;

public:
	Vehicle();
	Vehicle(std::istream& in);
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle(const char* companyName, eColor color, float price);
	virtual ~Vehicle();

	Vehicle& operator=(const Vehicle& other);
	Vehicle& operator=(Vehicle&& other) noexcept;

	virtual bool operator>(const Vehicle& other) final;
	virtual bool operator==(const Vehicle& other) final;

	friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);
	friend std::istream& operator>>(std::istream& in, Vehicle& v);

	virtual float getPrice() const final { return price; }
	virtual const char* getColor() const final { return colorArr[color]; }
	virtual const char* getCompanyName() const final { return companyName; }

	bool setColor(const eColor color);
	virtual void raisePrice() = 0;

	virtual Vehicle* Clone() const = 0;
};