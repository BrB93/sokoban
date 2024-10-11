#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sokoban.h"



#define SIZE 10
int main()
{
	char **board = init_board();

	display_board(board);

	

for (int i = 0; i < SIZE; i++) {
    free(board[i]);
}
free(board);
return 0;
}