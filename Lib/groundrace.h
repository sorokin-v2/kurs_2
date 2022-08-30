#pragma once
#include "race.h"
#include "groundvehicle.h"
#include <string>

#ifdef Lib_EXPORTS                                          //ИМЯ И РЕГИСТР ВАЖНЫ!!! в проекте библиотеки DLL Visual Studio автоматически определяет макрос <ИМЯПРОЕКТА>_EXPORTS
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllimport)
#else
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllexport)
#endif


class GroundRace : public Race {
public:
	DYNAMICLIBRARYDYNAMIC_API GroundRace();
	DYNAMICLIBRARYDYNAMIC_API ~GroundRace();
	DYNAMICLIBRARYDYNAMIC_API bool AddVehicle(const size_t) override;
	DYNAMICLIBRARYDYNAMIC_API virtual bool IsRegistered(const std::string&) override;
	DYNAMICLIBRARYDYNAMIC_API virtual std::string GetRegisteredVehicles() override;
	DYNAMICLIBRARYDYNAMIC_API virtual std::string StartRace(const int) override;

private:
	GroundVehicle** _vehicles;

};
