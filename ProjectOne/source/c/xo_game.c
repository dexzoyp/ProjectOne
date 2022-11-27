#include "xo_game.h"
#include "functions.h"
#include <stdio.h>
const int WIN = 3;

int check_winner(int count, char first)
{
	if (count == WIN)
	{
		if (first == 'X') {
			return PlayerX;
		}
		else if (first == 'O') {
			return PlayerO;
		}
		else {
			return 0;
		}
	}
	return 0;
}

int check_rows(char** arr, char empty_symbol)
{
	int rows = my_2Dstrlen(arr);
	int columns = my_strlen(arr[0]);
	for (int i = 0; i < rows; i++)
	{
		char first = arr[i][0];
		if (first == empty_symbol)
		{
			continue;
		}
		int count = 1;
		for (int j = 1; j < columns; j++)
		{
			if (first == arr[i][j]) {
				count++;
			}
			else {
				break;
			}
		}
		int winner = check_winner(count, first);
		if (winner) {
			return winner;
		}
	}
	return 0;
}
int check_columns(char** arr, char empty_symbol)
{
	int rows = my_2Dstrlen(arr);
	int columns = my_strlen(arr[0]);
	for (int i = 0; i < rows; i++)
	{
		char first = arr[0][i];
		if (first == empty_symbol)
		{
			continue;
		}
		int count = 1;
		for (int j = 1; j < columns; j++)
		{
			if (first == arr[j][i]) {
				count++;
			}
			else {
				break;
			}
		}
		int winner = check_winner(count, first);
		if (winner) {
			return winner;
		}
	}
	return 0;
}
int check_main_diagonal(char** arr, char empty_symbol)
{
	char first = arr[0][0];
	int rows = my_2Dstrlen(arr);
	if (first == empty_symbol) {
		return 0;
	}
	int count = 1;
	for (int i = 1; i < rows; i++)
	{
		if (first == arr[i][i]) {
			count++;
		}
		else {
			break;
		}
	}
	return check_winner(count, first);
}
int check_secondary_diagonal(char** arr, char empty_symbol)
{
	int columns = my_strlen(arr[0]);
	char first = arr[0][columns - 1];
	if (first == empty_symbol) {
		return 0;
	}
	int count = 1;
	for (int i = 1; i < columns; i++)
	{
		if (first == arr[i][columns - 1 - i]) {
			count++;
		}
		else {
			break;
		}
	}
	return check_winner(count, first);
}
const int max_rounds = 9;
#define winner_conditions 4
int check_game_over(char** matrix, int  round, char empty_symbol)
{
	int winner[winner_conditions];
	winner[0] = check_rows(matrix, empty_symbol);
	winner[1] = check_columns(matrix, empty_symbol);
	winner[2] = check_main_diagonal(matrix, empty_symbol);
	winner[3] = check_secondary_diagonal(matrix, empty_symbol);

	for (int i = 0; i < winner_conditions; i++)
	{
		if (winner[i] != 0) {
			print_char_matrix(matrix, 1);
			if (winner[i] == PlayerX) {
				printf("Winner is: X");
				return PlayerX;
			}
			else {
				printf("Winner is: O");
				return PlayerO;
			}
		}
	}
	if (round == max_rounds) {
		print_char_matrix(matrix, 1);
		printf("Draw!");
		return Draw;
	}
	return 0;
}
void start_xo_game()
{
	int rows = 3;
	int columns = 3;
	char empty_symbol = '*';
	char** matrix = create_char_matrix(rows, columns, empty_symbol);

	int round = 0;
	int player = PlayerX;
	int x = -1;
	int y = -1;

	//main loop
	while (!check_game_over(matrix, round, empty_symbol))
	{
		print_char_matrix(matrix, 1);
		scanf_s("%d %d", &x, &y);

		//Invalid input
		if (x < 0 || x > rows - 1 && y < 0 || y > columns - 1)
			continue;

		//Already choosen
		if (matrix[x][y] != empty_symbol)
			continue;

		round++;
		if (player == PlayerX) {
			matrix[x][y] = 'X';
			player = PlayerO;
		}
		else {
			matrix[x][y] = 'O';
			player = PlayerX;
		}
	}
}