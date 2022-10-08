//#define C

#ifdef C
extern "C" {
	#include <stdio.h>
	}
#else
	#include <iostream>
	#include <iomanip>
	#include "cpp/functions.hpp"
#endif




int main()
{
	FindRoot(1, 2, -15);
}