#include "VehicleSorter.h"

const std::string VehicleSorter::strategyName[VehicleSorter::eNofStrategy] = { "BubbleDown", "BubbleUp" };

VehicleSorter::VehicleSorter(sortType type) : type(type)
{
}

VehicleSorter::~VehicleSorter()
{
}
