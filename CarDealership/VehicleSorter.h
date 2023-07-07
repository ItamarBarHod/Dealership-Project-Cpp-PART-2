#pragma once

#include <vector>
#include "Vehicle.h"

class VehicleSorter {
public:
	typedef enum { eBubbleDown, eBubbleUp, eNofStrategy } sortType;
	static const std::string strategyName[eNofStrategy];

	VehicleSorter(sortType type);
	virtual ~VehicleSorter();

	const std::string& getStrategyName() const { return strategyName[type]; }

	virtual int getType() const = 0;
	virtual void sortVehicles(std::vector<Vehicle*>& vehicleArr) const = 0;
private:
	sortType type;
};