#pragma once

#include "General.h"

class Vehicle {
private:
	static const float CLEAN_FACTOR;
public:
	typedef enum { eCar, eBoat, eSuperBoatCar, eNofVehicle } eVehicle;
	typedef enum { eWhite, eBlack, eBlue, eRed, eYellow, ePurple, eNofColor } eColor;
	typedef enum { eFerari, eSkoda, eHonda, eToyota, eMazda, eVolvo, eTesla, eNofManufacturer } eManufacturer;
protected:
	const float factorArr[eNofVehicle] = { 1.4F, 1.3F, 2.0F };
	const char* colorArr[eNofColor] = { "White", "Black", "Blue", "Red", "Yellow", "Purple" };
	const char* manufacturerArr[eNofManufacturer] = { "Ferari", "Skoda", "Honda", "Toyota", "Mazda", "Volvo", "Tesla" };

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

	virtual bool operator>(const Vehicle& other) final;
	virtual bool operator==(const Vehicle& other) final;

	void operator++();

	friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);
	friend std::istream& operator>>(std::istream& in, Vehicle& vehicle);

	float getPrice() const { return price; }
	const char* getColor() const { return colorArr[color]; }
	const char* getCompanyName() const { return companyName; }
	bool getCleanStatus() const { return isClean; }

	virtual void raisePrice() = 0;
	virtual int getType() const = 0;

	virtual Vehicle* Clone() const = 0;
};