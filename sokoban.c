#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sokoban.h"


#define SIZE 10


char ** init_board(int pos_i, int pos_j)
{
	char ** board = malloc(SIZE * sizeof(char *));
	for (int i = 0; i < SIZE; i++)
	{
		board[i] = malloc(SIZE * sizeof(char));
		for (int j = 0; j < SIZE; j++)
		{
			if (i == 0 || i == SIZE - 1 || j == 0 || j == SIZE - 1)
			{
				board[i][j] = '#'; // MUR
			} else {
				board[i][j] = ' '; // VIDE
			}
		}	
	}
	board[pos_i][pos_j] = 'o';


	return board;

}

void display_board(char **board){
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
