#pragma once

#include "General.h"

class Vehicle {
private:
	static const float CLEAN_FACTOR;
public:
	typedef enum { eCar, eBoat, eSuperBoatCar, eNofType } eVehicleType;
	typedef enum { eWhite, eBlack, eBlue, eRed, eYellow, ePurple, eNofColor } eColor;
	typedef enum { eFerari, eSkoda, eHonda, eToyota, eMazda, eVolvo, eTesla, eNofManufacturer } eManufacturer;
	static const char* vehicleTypeArr[eNofType];
protected:
	static const float factorArr[eNofType];
	static const char* colorArr[eNofColor];
	static const char* manufacturerArr[eNofManufacturer];

protected:
	const char* companyName;
	eColor color;
	float price;
	bool isClean;

protected:
	virtual std::ostream& print(std::ostream& out) const;
	virtual std::istream& read(std::istream& in);
	virtual int getSpeed() const = 0;

private:
	void printManufacturer() const;
	void printColors() const;
	int chooseCompany() const;
	eColor chooseColor() const;

public:
	Vehicle(std::istream& in);
	Vehicle(const char* companyName, eColor color, float price);
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(const Vehicle& other);
	Vehicle& operator=(Vehicle&& other) noexcept;
	virtual ~Vehicle();

	bool operator>(const Vehicle& other) const { return price > other.price; }
	bool operator<(const Vehicle& other) const { return price < other.price; }
	bool operator==(const Vehicle& other) const;

	const Vehicle& operator++(); // non const

	friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);

	float getPrice() const { return price; }
	const char* getColor() const { return colorArr[color]; }
	const char* getCompanyName() const { return companyName; }
	bool getCleanStatus() const { return isClean; }

	virtual void raisePrice() = 0;
	virtual int getType() const = 0;

	void printVehicle() const;
};