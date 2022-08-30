#pragma once
#include <string>

#ifdef Lib_EXPORTS                                          //��� � ������� �����!!! � ������� ���������� DLL Visual Studio ������������� ���������� ������ <����������>_EXPORTS
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllimport)
#else
#define DYNAMICLIBRARYDYNAMIC_API __declspec(dllexport)
#endif

class Vehicle {
public:
	std::string GetName() { return _name; }
	double GetRaceTime() { return _race_time; }

protected:
	Vehicle(const std::string&, const int);										//��������� ��������� ���������� ����� ������ �.�. �� ������������ ������ � �������� ��������

	int _speed{0};
	std::string _name{"�� �������"};
	double _race_time{ 0 };

private:
};

