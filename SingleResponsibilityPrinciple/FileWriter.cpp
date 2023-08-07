#include "FileWriter.h"
#include "Management.h"
#include <iostream>

void FileWriter::SaveToFile(const Management& m)
{
	auto employees = m.GetEmployees();
	for (auto& it : employees) {
		SaveEmployee(it);
	}
}

void FileWriter::SaveEmployee(const Employee& e)
{
	std::cout << e.GetName() << " Saved Filed!\n";
}
