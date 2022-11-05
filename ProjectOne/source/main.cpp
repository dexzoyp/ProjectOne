//#define C

#ifdef C
extern "C" {
	#include <stdio.h>
	#include <stdlib.h>
	#include "c/functions.h"
	}
#else
	#include <iostream>
	#include <iomanip>
	#include "cpp/functions.hpp"
#endif

int main()
{

}