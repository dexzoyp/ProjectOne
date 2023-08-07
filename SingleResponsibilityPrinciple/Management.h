#pragma once
#include "Employee.h"
#include <vector>
class Management
{
public:
	Management() = default;
	inline const std::vector<Employee>& GetEmployees() const { return m_employees; }
	void AddEmployee(Employee e);
private:
	std::vector<Employee> m_employees;
};

