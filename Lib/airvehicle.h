#pragma once
#include "vehicle.h"
#include <string>

class AirVehicle : public Vehicle {
public:
	
	AirVehicle(const size_t);
	void CalcRaceTime(const int);

protected:

private:
};
