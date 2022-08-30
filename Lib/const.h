#pragma once
#include <string>

//Параметры наземных транспортных средств
const std::string GroundNames[] = { "верблюд", "верблюд-быстроход", "кентавр", "ботинки-вездеходы" };
const int GroundSpeed[] = { 10, 40, 15, 6 };
const int GroundDrivingTime[] = { 30, 10 ,8 ,60 };
const int GroungFirstRestDuration[] = { 5, 5, 2, 10 };
const double GroundSecondRestDuration[] = { 0, 6.5, 0, 0 };
const int GroundАllSubsequent[] = { 8, 8, 2, 5 };

//Параметры воздушных транспортных средств
const std::string AirNames[] = { "ковер-самолет", "орёл", "метла" };
const int AirSpeed[] = { 10, 8, 20 };
