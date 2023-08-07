#pragma once

class Employee;
class Management;
class FileWriter
{
public:
	FileWriter() = default;
	void SaveToFile(const Management& m);
private:
	void SaveEmployee(const Employee& e);
};

