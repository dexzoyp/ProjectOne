#include "functions.hpp"
#include <iostream>
#include <iomanip>
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