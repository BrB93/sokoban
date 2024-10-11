#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

char **init_board() {
	char **board;
	int i, j;

	board = malloc(SIZE * sizeof(*board));
	for (int i = 0; i < SIZE; i++)
	{
		board[i] = malloc(SIZE * sizeof(char));
		for (int j = 0; j < SIZE; j++)
		{
			if (i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1)
			{
				board[i][j] = '#';
			} else {
				board[i][j] = ' ';
			}
		}
	}

board[1][1] = 'o';
board[2][2] = 'X';
board[2][3] = '.';

return board;
}

void display_board(char **board){
	int i, j;

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	char **board = init_board();
	display_board(board);
	for (int i = 0; i < SIZE; i++)
	{
		free(board[i]);
	}
	free(board);
	
	return 0;
}