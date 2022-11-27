#define C

#ifdef C
extern "C" {
	#include <stdio.h>
	#include <stdlib.h>
	#include "c/functions.h"
	#include "c/xo_game.h"
	}
#else
	#include <iostream>
	#include <iomanip>
	#include "cpp/functions.hpp"
#endif

int main(int argc, char* argv[])
{
	start_xo_game();
	return 0;
}	