#include "mixedrace.h"
#include "const.h"
#include <sstream>

MixedRace::MixedRace() : Race()
{
	_av = new AirVehicle* [std::size(AirNames)]();
	_gv = new GroundVehicle * [std::size(GroundNames)]();
}

MixedRace::~MixedRace()
{
	for (int i = 0; i < _air_vehicle_count; ++i)
	{
		delete _av[i];
	}
	delete[] _av;
	for (int i = 0; i < _ground_vehicle_count; ++i)
	{
		delete _gv[i];
	}
	delete[] _gv;
}

bool MixedRace::IsRegistered(const std::string& VehicleName)
{
	for (int i = 0; i < _air_vehicle_count; ++i)
	{
		if (_av[i]->GetName() == VehicleName) return true;
	}
	for (int i = 0; i < _ground_vehicle_count; ++i)
	{
		if (_gv[i]->GetName() == VehicleName) return true;
	}
	return false;
}

std::string MixedRace::GetRegisteredVehicles()
{
	std::string out = "";
	for (int i = 0; i < _air_vehicle_count; ++i)
	{
		out += _av[i]->GetName() + " ";
	}
	for (int i = 0; i < _ground_vehicle_count; ++i)
	{
		out += _gv[i]->GetName() + " ";
	}
	return out;
}

bool MixedRace::AddVehicle(const size_t VehicleIndex)
{
	if (VehicleIndex >= 0 && VehicleIndex < std::size(GroundNames) + std::size(AirNames))
	{
		if (VehicleIndex < std::size(AirNames))	//Индекс из состава воздушных тс
		{
			_av[_air_vehicle_count++] = new AirVehicle(VehicleIndex);
		}
		else
		{
			_gv[_ground_vehicle_count++] = new GroundVehicle(VehicleIndex - std::size(AirNames));
		}
		++_vehicle_count;
		return true;
	}
	else return false;
}

std::string MixedRace::StartRace(const int TrackLength)
{
	for (int i = 0; i < _air_vehicle_count; ++i)
	{
		_av[i]->CalcRaceTime(TrackLength);
	}
	for (int i = 0; i < _ground_vehicle_count; ++i)
	{
		_gv[i]->CalcRaceTime(TrackLength);
	}
	//Собираем имена и время прохождения наземных и воздушных ТС в массивы
	std::string* VehicleNames = new std::string[_vehicle_count];
	double* VehicleTime = new double[_vehicle_count];
	for (int i = 0; i < _air_vehicle_count; ++i)
	{
		VehicleNames[i] = _av[i]->GetName();
		VehicleTime[i] = _av[i]->GetRaceTime();
	}
	for (int i = 0; i < _ground_vehicle_count; ++i)
	{
		VehicleNames[i + _air_vehicle_count] = _gv[i]->GetName();
		VehicleTime[i + _air_vehicle_count] = _gv[i]->GetRaceTime();
	}
	//Пузырьковая сортировка результатов
	for (int i = 0; i < _vehicle_count; i++)
	{
		for (int j = 0; j < _vehicle_count - 1; j++)
		{
			if (VehicleTime[j] > VehicleTime[j + 1])
			{
				std::string tmp_string = VehicleNames[j];
				double tmp_double = VehicleTime[j];
				VehicleNames[j] = VehicleNames[j + 1];
				VehicleTime[j] = VehicleTime[j + 1];
				VehicleNames[j + 1] = tmp_string;
				VehicleTime[j + 1] = tmp_double;
			}
		}
	}
	std::ostringstream os;
	os << "Результаты гонки:\n";
	for (int i = 0; i < _vehicle_count; ++i)
	{
		os << std::to_string(i + 1) << ". " << VehicleNames[i] << ". Время: " << VehicleTime[i] << "\n";
	}
	return os.str();

}


