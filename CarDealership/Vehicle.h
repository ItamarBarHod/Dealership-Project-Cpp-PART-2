#include <iostream>
#include "General.h"

class Vehicle {
protected:
	const char* companyName;
	COLOR color;
	unsigned price;
	const float sellFactor;
public:

	Vehicle(const char* companyName, COLOR color, unsigned price);
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other);
	const Vehicle& operator=(const Vehicle& other);
	const Vehicle& operator=(Vehicle&& other);
	virtual ~Vehicle();

	virtual friend std::ostream& operator<<(std::ostream& out, const Vehicle& v);
	virtual bool operator>(const Vehicle& v) = 0;
	bool operator==(const Vehicle& v); // if same color and company

	unsigned getPrice() const;
	void setColor(COLOR color);
	const char* getColor() const;
	const char* getCompany() const;
	virtual void setPrice() = 0;
	virtual int getSpeed() const = 0;
};