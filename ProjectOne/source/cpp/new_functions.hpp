#pragma once
#include <vector>
#include <string>
void FindRoot(double a, double b, double c);
void Create2DMatrix(std::vector<std::vector<int>>& matrix, int rows, int columns, int fill);
void Print2DMatrix(std::vector<std::vector<int>>& matrix);
void Fill2DMatrix(std::vector<std::vector<int>>& matrix, int fill);
void Delete2DMatrix(std::vector<std::vector<int>>& matrix);
void writeToFile(std::string filename, std::string data);
std::vector<std::string> readFromFile(std::string filename);