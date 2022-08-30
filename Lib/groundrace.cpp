#include "groundrace.h"
#include "const.h"
#include <sstream>

GroundRace::GroundRace() : Race()
{
	_vehicles = new GroundVehicle* [std::size(GroundNames)]();
}

GroundRace::~GroundRace()
{
	for (int i = 0; i < _vehicle_count; ++i)
	{
		delete _vehicles[i];
	}
	delete[] _vehicles;
}

bool GroundRace::IsRegistered(const std::string& VehicleName)
{
	for (int i = 0; i < _vehicle_count; ++i)
	{
		if (_vehicles[i]->GetName() == VehicleName) return true;
	}
	return false;
}

std::string GroundRace::GetRegisteredVehicles()
{
	std::string out = "";
	for (int i = 0; i < _vehicle_count; ++i)
	{
		out += _vehicles[i]->GetName() + " ";
	}
	return out;
}

bool GroundRace::AddVehicle(const size_t VehicleIndex)
{
	if (VehicleIndex >= 0 && VehicleIndex < std::size(GroundNames))
	{
		_vehicles[_vehicle_count++] = new GroundVehicle(VehicleIndex);
		return true;
	}
	else return false;
}

std::string GroundRace::StartRace(const int TrackLength)
{
	for (int i = 0; i < _vehicle_count; ++i)
	{
		_vehicles[i]->CalcRaceTime(TrackLength);
	}
	//Пузырьковая сортировка результатов
	for (int i = 0; i < _vehicle_count; i++)
	{
		for (int j = 0; j < _vehicle_count - 1; j++)
		{
			if (_vehicles[j]->GetRaceTime() > _vehicles[j + 1]->GetRaceTime())
			{
				GroundVehicle* tmp = _vehicles[j];
				_vehicles[j] = _vehicles[j + 1];
				_vehicles[j + 1] = tmp;
			}
		}
	}
	std::ostringstream os;
	os << "Результаты гонки:\n";
	for (int i = 0; i < _vehicle_count; ++i)
	{
		os << std::to_string(i + 1) << ". " << _vehicles[i]->GetName() << ". Время: " << _vehicles[i]->GetRaceTime() << "\n";
	}
	return os.str();
}
