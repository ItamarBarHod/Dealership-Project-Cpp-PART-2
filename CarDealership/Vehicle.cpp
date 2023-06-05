#include "Vehicle.h"

std::ostream& Vehicle::toOs(std::ostream& out) const
{

}

bool Vehicle::setColor(const eColor color)
{
	if (color < 0 || color > eNofColor)
		return false;
	this->color = color;
	return true;
}
