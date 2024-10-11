#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

#define SIZE 8

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
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}

void move_player(char **board, int *player_x, int *player_y){
	char move;
	printf("Entrez un mouvement (w = haut, s = bas, a = gauche, d = droite) : ");
	scanf(" %c", &move);

	int new_x = *player_x;
	int new_y = *player_y;
	int next_x = new_y;
	int next_y = new_x;

	if(move == 'w') new_x--, next_x = new_x - 1;

	else if (move == 's') new_x++, next_x + 1;

	else if (move == 'a') new_y--, next_y = new_y - 1;
	
	else if (move == 'd') new_y++, next_y = new_y + 1;

	else{
		printf("Impossible de traverser les murs !\n");
		return;
	}


	if (board[new_x][new_y] == 'X')
	{
		if (board[next_x][next_y] == ' ')
		{
			board[next_x][next_y] = 'X';

			board[*player_x][*player_y] = ' ';

			board[*player_x][*player_y] = 'o';
		
			*player_x = new_x;

			*player_y = new_y;

			if (board[next_x][next_y] == '.')
			{
				printf("Victoire !\n");
				exit(0);
			}

		} else {
			printf("Impossible de traverser les murs !\n");
		}
	}


	else if (board[new_x][new_y] == ' ')
	{
		board[*player_x][*player_y] = ' ';
		*player_x = new_x;
		*player_y = new_y;
		board[*player_x][*player_y] = 'o';
	}

	else if (board[new_x][new_y] == '#')
	{
		printf("Impossible de traverser les murs !\n");
	} else{
		printf("Mouvement invalide ! \n");
	}
}

int main()
{
	int player_x = 1;
	int player_y = 1;
	char **board = init_board();

	while (1){
		system("clear");
		display_board(board);
		move_player(board, &player_x, &player_y);
	}	


	for (int i = 0; i < SIZE; i++)
	{
		free(board[i]);
	}
	free(board);


	return 0;
}