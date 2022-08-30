#include "airvehicle.h"
#include "const.h"

AirVehicle::AirVehicle(const size_t VehicleIndex) : Vehicle(AirNames[VehicleIndex], AirSpeed[VehicleIndex])
{
}

void AirVehicle::CalcRaceTime(const int TrackLength)
{
	if (_name == "ковер-самолет")
	{
		if (TrackLength < 1000)
		{
			_race_time = static_cast<double>(TrackLength) / _speed;
		}
		else
		{
			if (TrackLength >= 1000 && TrackLength < 5000)
			{
				_race_time = (static_cast<double>(TrackLength) * 0.97) / _speed;
			}
			else
			{
				if (TrackLength >= 5000 && TrackLength < 10000)
				{
					_race_time = (static_cast<double>(TrackLength) * 0.9) / _speed;
				}
				else
				{
					_race_time = (static_cast<double>(TrackLength) * 0.95) / _speed;
				}
			}
		}
	}
	else
	{
		if (_name == "орёл")
		{
			_race_time = (static_cast<double>(TrackLength) * 0.94) / _speed;
		}
		else
		{
			if (_name == "метла")
			{
				_race_time = (static_cast<double>(TrackLength) * (100 - static_cast<int>(TrackLength) / 1000) / 100.0) / _speed;
			}
			else
			{
				return;	//Неизвестный тип ТС
			}
		}
	}	
}

