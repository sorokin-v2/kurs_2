#pragma once
#include "vehicle.h"

#ifdef Lib_EXPORTS                                          //ИМЯ И РЕГИСТР ВАЖНЫ!!! в проекте библиотеки DLL Visual Studio автоматически определяет макрос <ИМЯПРОЕКТА>_EXPORTS
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllimport)
#else
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllexport)
#endif



class GroundVehicle : public Vehicle {
public:
	GroundVehicle(const size_t);
	void CalcRaceTime(const int TrackLength);

protected:
private:
	int _driving_time{ 0 };
	int _first_rest_duration{ 0 };
	double _second_rest_duration{ 0 };
	int _all_subsequent{ 0 };
};

