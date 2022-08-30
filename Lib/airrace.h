#pragma once
#include "race.h"
#include "airvehicle.h"
#include<string>

#ifdef Lib_EXPORTS                                          //��� � ������� �����!!! � ������� ���������� DLL Visual Studio ������������� ���������� ������ <����������>_EXPORTS
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllimport)
#else
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllexport)
#endif


class AirRace : public Race {
public:

	DYNAMICLIBRARYDYNAMIC_API AirRace();
	DYNAMICLIBRARYDYNAMIC_API ~AirRace();
	DYNAMICLIBRARYDYNAMIC_API virtual bool IsRegistered(const std::string&) override;
	DYNAMICLIBRARYDYNAMIC_API virtual std::string GetRegisteredVehicles() override;
	DYNAMICLIBRARYDYNAMIC_API virtual bool AddVehicle(const size_t) override;
	DYNAMICLIBRARYDYNAMIC_API virtual std::string StartRace(const int) override;

private:
	AirVehicle** _vehicles;
};
