#pragma once
#include <string>

#ifdef Lib_EXPORTS                                          //ИМЯ И РЕГИСТР ВАЖНЫ!!! в проекте библиотеки DLL Visual Studio автоматически определяет макрос <ИМЯПРОЕКТА>_EXPORTS
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllimport)
#else
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllexport)
#endif

class Vehicle {
public:
	std::string GetName() { return _name; }
	double GetRaceTime() { return _race_time; }

protected:
	Vehicle(const std::string&, const int);										//Запрещаем создавать экземпляры этого класса т.к. он используется ТОЛЬКО в качестве базового

	int _speed{0};
	std::string _name{"Не указано"};
	double _race_time{ 0 };

private:
};

