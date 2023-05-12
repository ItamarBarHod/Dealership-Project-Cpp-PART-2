#include "Vehicle.h"

class Boat : virtual public Vehicle {
private:
	int sailingSpeed;
	int numOfSails;
public:
	Boat(const char* companyName, COLOR color, unsigned price, int sailingSpeed = 90, int numOfSails = 1);

	virtual int getSpeed() const;
	virtual int getNumOfSails() const;
	virtual void setPrice() const;
	void setSail(int numOfSails);
};
