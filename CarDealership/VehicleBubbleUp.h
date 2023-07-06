#pragma once

#include "VehicleSorter.h"

class VehicleBubbleUp : public VehicleSorter {
	int getType() const override { return eBubbleUp; }
	virtual void sortVehicles(std::vector<Vehicle*>&) const override;
public:
	VehicleBubbleUp(sortType type);
};