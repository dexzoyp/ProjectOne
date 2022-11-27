#pragma once
enum GameOver
{
	PlayerX = 1,
	PlayerO,
	Draw
};
int check_winner(int count, char first);
int check_rows(char** arr, char empty_symbol);
int check_columns(char** arr, char empty_symbol);
int check_main_diagonal(char** arr, char empty_symbol);
int check_secondary_diagonal(char** arr, char empty_symbol);
int check_game_over(char** matrix, int  round, char empty_symbol);
void start_xo_game();