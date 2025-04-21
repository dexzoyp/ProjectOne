//#define C

#ifdef C
extern "C" {
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "c/functions.h"
	#include "c/xo_game.h"
	}
#else
	#include <iostream>
	#include <iomanip>
	#include <algorithm>
#include "cpp/new_functions.hpp"
#include "cpp/dependency.hpp"
#endif

int main(int argc, char* argv[])
{
	AggregationCode();
	return 0;
}