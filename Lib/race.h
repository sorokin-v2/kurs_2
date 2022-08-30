#pragma once
#include <string>

class Race {
public:
	int GetVehicleCount() { return _vehicle_count; }
	virtual bool IsRegistered(const std::string&) = 0;
	virtual std::string GetRegisteredVehicles() = 0;
	virtual bool AddVehicle(const size_t) = 0;
	virtual std::string StartRace(const int) = 0;

protected:
	Race() {}							//������ ����������� �������� ���������� ����� ������ �.�. �� ������ �������������� ������ ��� �������
	int _vehicle_count{ 0 };

};
