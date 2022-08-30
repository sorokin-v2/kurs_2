#include "groundvehicle.h"
#include "const.h"


GroundVehicle::GroundVehicle(const size_t VehicleIndex) : Vehicle(GroundNames[VehicleIndex], GroundSpeed[VehicleIndex]),
_driving_time{ GroundDrivingTime[VehicleIndex] }, _first_rest_duration{ GroungFirstRestDuration[VehicleIndex]},
_second_rest_duration{ GroundSecondRestDuration[VehicleIndex] }, _all_subsequent{ GroundАllSubsequent[VehicleIndex] }
{

}

void GroundVehicle::CalcRaceTime(const int TrackLength)
{
	double TimeLeft = static_cast<double>(TrackLength) / _speed;
	_race_time = TimeLeft;
	if (TimeLeft > _driving_time)
	{
		_race_time += _first_rest_duration;
		TimeLeft -= _driving_time;
		if (_second_rest_duration > 0 && TimeLeft > _driving_time)	//Надо делать второй перерыв
		{
			_race_time += _second_rest_duration;
			TimeLeft -= _driving_time;
		}
		_race_time += _all_subsequent * (static_cast<int>(TimeLeft / _driving_time));	//Добавляем время последующих отдыхов
	}
	return;
}
