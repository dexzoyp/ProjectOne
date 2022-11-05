#ifndef functions_c
#define functions_c
int* new_array(int size, int fill);
void print_array(int* arr, int size);
void fill_array(int* arr, int size, int fill);
void delete_array(int* arr);

int** new_2d_array(int rows, int columns, int fill);
void fill_2d_array(int** arr, int rows, int columns, int fill);
void print_2d_array(int** arr, int rows, int columns);
void delete_2d_array(int** arr, int rows);
#endif // !functions
