#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sokoban.h"



#define SIZE 10
int main()
{
	srand(time(NULL));
	int pos_i = rand() % (SIZE - 2) + 1;
	int pos_j = rand() % (SIZE - 2) + 1;

	char **board = init_board(pos_i, pos_j);

	display_board(board);

	

for (int i = 0; i < SIZE; i++) {
    free(board[i]);
}
free(board);
return 0;
}