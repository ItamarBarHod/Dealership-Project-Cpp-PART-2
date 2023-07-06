#pragma once

#include "VehicleSorter.h"

class VehicleBubbleDown : public VehicleSorter {
	int getType() const override { return eBubbleDown; }
	virtual void sortVehicles(std::vector<Vehicle*>& vehicleArr) const override;
public:
	VehicleBubbleDown(sortType type);
};