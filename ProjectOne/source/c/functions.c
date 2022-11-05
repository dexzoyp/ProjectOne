#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

#pragma warning ( push )
#pragma warning ( disable : 6396 )
int* new_array(int size, int fill)
{
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr != NULL) {
		for (int i = 0; i < size; i++)
		{
			arr[i] = fill;
		}
	}
	return arr;
}
#pragma warning ( pop )

void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}
void fill_array(int* arr, int size, int fill)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = fill;
	}
}
void delete_array(int* arr)
{
	free(arr);
}

int** new_2d_array(int rows, int columns, int fill)
{
	int** arr = (int**)malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++)
	{
		arr[i] = (int*)malloc(sizeof(int*) * columns);
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = fill;
		}
	}
	return arr;
}
void fill_2d_array(int** arr, int rows, int columns, int fill)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = fill;
		}
	}
}
void print_2d_array(int** arr, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%d, ", arr[i][j]);
		}
		printf("\n");
	}
}
void delete_2d_array(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(arr[i]);
	}
	free(arr);
}