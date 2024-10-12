#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sokoban.h"



#define SIZE 10
int main()
{
	srand(time(NULL));

	int pos_i, pos_j, pos_ca, pos_cb, pos_ga, pos_gb;

    do {
        pos_i = rand() % (SIZE - 2) + 1; // JOUEUR
        pos_j = rand() % (SIZE - 2) + 1;

        pos_ca = rand() % (SIZE - 2) + 1; // CAISSE
        pos_cb = rand() % (SIZE - 2) + 1;

        pos_ga = rand() % (SIZE - 2) + 1; // GOAL
        pos_gb = rand() % (SIZE - 2) + 1;

    } while ((pos_i == pos_ca && pos_j == pos_cb) ||  
             (pos_i == pos_ga && pos_j == pos_gb) ||  
             (pos_ca == pos_ga && pos_cb == pos_gb)); 

	printf("Joueur : %d %d\n", pos_i, pos_j);
	printf("Caisse : %d %d\n", pos_ca, pos_cb);
	printf("Goal : %d %d\n", pos_ga, pos_gb);

	char **board = init_board(pos_i, pos_j, pos_ca, pos_cb, pos_ga, pos_gb);

	display_board(board);


for (int i = 0; i < SIZE; i++) {
    free(board[i]);
}
free(board);
return 0;
}