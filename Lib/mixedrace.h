#pragma once
#include "race.h"
#include "airvehicle.h"
#include "groundvehicle.h"

#ifdef Lib_EXPORTS                                          //ИМЯ И РЕГИСТР ВАЖНЫ!!! в проекте библиотеки DLL Visual Studio автоматически определяет макрос <ИМЯПРОЕКТА>_EXPORTS
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllimport)
#else
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllexport)
#endif


class MixedRace : public Race {
public:
	DYNAMICLIBRARYDYNAMIC_API MixedRace();
	DYNAMICLIBRARYDYNAMIC_API ~MixedRace();
	DYNAMICLIBRARYDYNAMIC_API virtual bool IsRegistered(const std::string&) override;
	DYNAMICLIBRARYDYNAMIC_API virtual std::string GetRegisteredVehicles() override;
	DYNAMICLIBRARYDYNAMIC_API bool AddVehicle(const size_t) override;
	DYNAMICLIBRARYDYNAMIC_API virtual std::string StartRace(const int) override;

private:
	AirVehicle** _av;
	GroundVehicle** _gv;
	int _air_vehicle_count{ 0 };
	int _ground_vehicle_count{ 0 };
};
