#include <iostream>
#include "airrace.h"
#include "groundrace.h"
#include "mixedrace.h"
#include "const.h"

enum class RaceType {
	GroundRace = 1,
	AirRace,
	MixedRace
};

bool GetIntValue(int& UserRaceType)
{
	std::string UserInput;
	std::cin >> UserInput;
	if (UserInput.find_first_not_of("-0123456789") == std::string::npos)
	{
		try
		{
			UserRaceType = std::stoi(UserInput);
		}
		catch (const std::out_of_range)
		{
			std::cout << "\nВы ввели слишком длинное число.\n\n";
			return false;
		}
		catch (...)
		{
			std::cout << "\nВы ввели некорректное число.\n\n";
			return false;
		}
		return true;
	}
	else
	{
		std::cout << "\nРазрешено вводить только цифры.\n\n";
		return false;
	}
}

RaceType GetRaceType()
{	
	bool IncorrectUserChoice = false;
	int UserRaceType = 0;
	do
	{
		IncorrectUserChoice = false;
		do
		{
			std::cout << static_cast<int>(RaceType::GroundRace) << ". Гонка для наземного транспорта\n";
			std::cout << static_cast<int>(RaceType::AirRace) << ". Гонка для воздушного транспорта\n";
			std::cout << static_cast<int>(RaceType::MixedRace) << ". Гонка для наземного и воздушного транспорта\n";
			std::cout << "Выберите тип гонки: ";
		} while (!GetIntValue(UserRaceType));
		if (static_cast<RaceType>(UserRaceType) < RaceType::GroundRace || static_cast<RaceType>(UserRaceType) > RaceType::MixedRace)
		{
			std::cout << "\nВы указали недопустимое значение.\n\n";
			IncorrectUserChoice = true;
		}
	} while (IncorrectUserChoice);
	return static_cast<RaceType>(UserRaceType);
}

int GetDistanceLen()
{
	int DistanceLen = 0;
	do
	{
		do
		{
			std::cout << "Укажите длину дистанции (она должна быть положительна): ";
		} while (!GetIntValue(DistanceLen));
		if (DistanceLen <= 0)
		{
			std::cout << "\nВы указали отрицательную или нулевую длину дистанции.\n\n";
		}
	} while (DistanceLen <= 0);
	return DistanceLen;
}

bool AddVehicle(Race* const race, const std::string* const VehicleNames, const size_t VehicleIndex)
{
	if (race->IsRegistered(VehicleNames[VehicleIndex]))
	{
			std::cout << "\n" << VehicleNames[VehicleIndex] << " уже зарегистрирован!\n";
			return false;
	}
	else
	{
		std::cout << "\n" << VehicleNames[VehicleIndex] << " успешно зарегистрирован!\n";
		return race->AddVehicle(VehicleIndex);
	}
}



void ShowMenuAddVehicle(const std::string* const VehicleNames, const size_t Count, Race* const race)
{
	if (race->GetVehicleCount() > 0)
	{
		std::cout << "Зарегистрированные транспортные средства: " << race->GetRegisteredVehicles() << "\n";
	}
	for (size_t i = 0; i < Count; ++i)
	{
		std::cout << i + 1 << ". " << VehicleNames[i] << "\n";
	}
	std::cout << "0. Закончить регистрацию\n";
}

bool VehicleRegist(const RaceType CurrentRaceType, Race* const race, const int TrackLength)
{
	//Формируем список из наименований наземных и воздушных ТС
	std::string MixedNames[std::size(AirNames) + std::size(GroundNames)];
	for (int i = 0; i < std::size(AirNames); ++i)
	{
		MixedNames[i] = AirNames[i];
	}
	for (int i = 0; i < std::size(GroundNames); ++i)
	{
		MixedNames[i + std::size(AirNames)] = GroundNames[i];
	}
	const int MIN_SELECTED_VEHICLE_COUNT = 2;
	int UserInput = -1;
	do
	{
		if (race->GetVehicleCount() < MIN_SELECTED_VEHICLE_COUNT)
		{
			std::cout << "\nДолжно быть зарегистрировано хотя бы " << MIN_SELECTED_VEHICLE_COUNT << " транспортных средств(а)\n";
		}
		UserInput = -1;
		size_t MaxUserInput = 0;
		do		
		{
			switch (CurrentRaceType)
			{
				case RaceType::AirRace:
				{
					std::cout << "Гонка для воздушного транспорта. Расстояние: " << TrackLength << "\n";
					ShowMenuAddVehicle(AirNames, std::size(AirNames), race);
					MaxUserInput = std::size(AirNames);
					break;
				}
				case RaceType::GroundRace:
				{
					std::cout << "Гонка для наземного транспорта. Расстояние: " << TrackLength << "\n";
					ShowMenuAddVehicle(GroundNames, std::size(GroundNames), race);
					MaxUserInput = std::size(GroundNames);
					break;
				}
				case RaceType::MixedRace:
				{
					std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << TrackLength << "\n";
					ShowMenuAddVehicle(MixedNames, std::size(MixedNames), race);
					MaxUserInput = std::size(MixedNames);
					break;
				}
				default:
				{
					std::cout << "\nНеизвестный тип гонки\n";
					return false;
				}
			}
			std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
			if (!GetIntValue(UserInput) || UserInput > MaxUserInput || UserInput < 0)
			{
				std::cout << "\nНекорректный ввод\n\n";
				UserInput = -1;
			}
			else 
			{
				if (UserInput > 0)
				{
					switch (CurrentRaceType)
					{
						case RaceType::AirRace:
						{
							AddVehicle(race, AirNames, UserInput - 1);
							break;
						}
						case RaceType::GroundRace:
						{
							AddVehicle(race, GroundNames, UserInput - 1);
							break;
						}
						case RaceType::MixedRace:
						{
							AddVehicle(race, MixedNames, UserInput - 1);
							break;
						}
						default:
						{
							std::cout << "\nНеизвестный тип гонки\n";
							return false;
						}
					}
				}
			}
		} while (UserInput != 0);
	} while (race->GetVehicleCount() < MIN_SELECTED_VEHICLE_COUNT);
	return true;
}

bool GetRegisteredVehicle(const RaceType CurrentRaceType, Race* const race, const int TrackLength)
{
	if (VehicleRegist(CurrentRaceType, race, TrackLength))
	{
		int UserInput = -1;
		do
		{
			std::cout << "\n1. Зарегистрировать транспорт\n";
			std::cout << "2. Начать гонку\n";
			std::cout << "Выберите действие: ";
			if (GetIntValue(UserInput))
			{
				if (UserInput == 1)
				{
					std::cout << "\n";
					if (!VehicleRegist(CurrentRaceType, race, TrackLength))
					{
						return false;
					}
				}
				else
				{
					if (UserInput != 2)
					{
						std::cout << "\nНекорректный ввод\n";
					}
				}
			}
			else UserInput = -1;

		} while (UserInput != 2);
		return true;
	}
	else return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Добро пожаловать в гоночный симулятор!\n";
	int UserChoice = -1;
	do
	{
		RaceType CurrentRaceType = GetRaceType();
		int TrackLength = GetDistanceLen();
		switch (CurrentRaceType)
		{
			case RaceType::GroundRace:
			{
				GroundRace GR;
				if (GetRegisteredVehicle(RaceType::GroundRace, static_cast<Race*>(&GR), TrackLength))
				{
					std::cout << GR.StartRace(TrackLength) << "\n";
				}
				else return -1;
				break;
			}
			case RaceType::AirRace:
			{
				AirRace AR;
				if (GetRegisteredVehicle(RaceType::AirRace, static_cast<Race*>(&AR), TrackLength))
				{
					std::cout << AR.StartRace(TrackLength) << "\n";
				}
				else return -1;
				break;
			}
			case RaceType::MixedRace:
			{
				MixedRace MR;
				if (GetRegisteredVehicle(RaceType::MixedRace, static_cast<Race*>(&MR), TrackLength))
				{
					std::cout << MR.StartRace(TrackLength) << "\n";
				}
				else return -1;
				break;
			}
			default:
			{
				std::cerr << "Неизвестный тип гонки\n";
				return 0;
			}
		}
		do
		{
			std::cout << "1. Провести еще одну гонку\n";
			std::cout << "2. Выйти\n";
			std::cout << "Выберите действие: ";
			if (GetIntValue(UserChoice))
			{
				if (UserChoice != 1 && UserChoice != 2)
				{
					std::cout << "\nНекорректный ввод\n\n";
				}
			}
			else UserChoice = -1;
		} while (UserChoice != 1 && UserChoice != 2);
	} while (UserChoice != 2);
}
