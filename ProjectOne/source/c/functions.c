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
		arr[i] = (int*)malloc(sizeof(int) * columns);
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
int my_strlen(const char* str)
{
	int size = 0;
	while (str[size] != '\0') {
		++size;
	}
	return size;
}
char* my_strcpy(char* destination, const char* source)
{
	int source_size = my_strlen(source);
	for (int i = 0; i < source_size; i++)
	{
		destination[i] = source[i];
	}
	destination[source_size] = '\0';
	return destination;
}
char* my_strcat(char* destination, const char* source)
{
	int source_size = my_strlen(source);
	int destination_size = my_strlen(destination);
	for (int i = 0; i < source_size; i++)
	{
		destination[destination_size + i] = source[i];
	}
	destination[source_size + destination_size] = '\0';
	return destination;
}
int my_strcmp(const char* lhs, const char* rhs)
{
	int i = 0;
	while (lhs[i]) {
		if (lhs[i] != rhs[i]) {
			break;
		}
		i++;
	}
	return (const unsigned char*)lhs[i] - (const unsigned char*)rhs[i];
}
