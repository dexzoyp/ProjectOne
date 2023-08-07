#pragma once
#include <string>

class Employee
{
public:
	Employee() = default;
	Employee(int id, std::string name, double salary);

	inline int GetId() const { return m_id; }
	inline std::string GetName() const { return m_name; }
	inline double GetSalary() const { return m_salary; }
private:
	int m_id;
	std::string m_name;
	double m_salary;

};

