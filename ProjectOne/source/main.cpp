//#define C

#ifdef C
extern "C" {
	#include <stdio.h>
	}
#else
	#include <iostream>
#endif

int main()
{
	//printf("Hello World!\n");
	std::cout << "Hello World!\n";
	return 0;
}