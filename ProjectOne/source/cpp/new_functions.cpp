#include "new_functions.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
void FindRoot(double a, double b, double c)
{
	//D = b^2 - 4ac
	if (a == 0 && b == 0) return;

	double D = static_cast<double>(b * b) - static_cast<double>(4 * a * c);

	if (D < 0) return;

	if (a == 0) {
		double x = static_cast<double>(c) / static_cast<double>(-b);
		std::cout << "X: " << std::setprecision(10) << x << std::endl;
		return;
	}

	//x1,x2 -b +- sqrt(D) /2a
	double x1 = static_cast<double>(-b + std::sqrt(D)) / static_cast<double>(2 * a);
	double x2 = static_cast<double>(-b - std::sqrt(D)) / static_cast<double>(2 * a);

	std::cout << "X1: " << std::setprecision(10) << x1 << std::endl;
	std::cout << "X2: " << std::setprecision(10) << x2 << std::endl;
}
void Create2DMatrix(std::vector<std::vector<int>>& matrix, int rows, int columns, int fill)
{
	for (int i = 0; i < rows; i++)
	{
		matrix.emplace_back(std::vector<int>());
		for (int j = 0; j < columns; j++)
		{
			matrix.at(i).push_back(fill);
		}
	}

}
void Print2DMatrix(std::vector<std::vector<int>>& matrix)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		for (unsigned int j = 0; j < matrix.at(i).size(); j++)
		{
			std::cout << matrix.at(i).at(j) << ", ";
		}
		std::cout << std::endl;
	}
}
void Fill2DMatrix(std::vector<std::vector<int>>& matrix, int fill)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		for (unsigned int j = 0; j < matrix.at(i).size(); j++)
		{
			matrix.at(i).at(j) = fill;
		}
	}
}
void Delete2DMatrix(std::vector<std::vector<int>>& matrix)
{
	matrix.clear();
}
void writeToFile(std::string filename, std::string data)
{
	std::ofstream file;
	file.open(filename);
	if (file.is_open())
	{
		file << data;
		file.close();
	}
}
std::vector<std::string> readFromFile(std::string filename)
{
	std::ifstream file;
	std::vector<std::string> allRows;
	file.open(filename);
	if (file.is_open())
	{
		std::string row = "";
		while (std::getline(file, row))
		{
			allRows.push_back(row);
			row.clear();
		}
		file.close();
	}
	return allRows;
}