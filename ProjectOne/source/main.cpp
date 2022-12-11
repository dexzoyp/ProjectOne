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
#endif

int main(int argc, char* argv[])
{
	return 0;
}	