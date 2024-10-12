#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sokoban.h"


#define SIZE 10


char ** init_board(int pos_i, int pos_j, int pos_ca, int pos_cb, int pos_ga, int pos_gb)
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
	board[pos_ca][pos_cb] = 'X';
	board[pos_ga][pos_gb] = '.';
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

void move(char **board, int *pos_i, int *pos_j, int *pos_ca, int *pos_cb, int pos_ga, int pos_gb) {
    char direction;
    printf("Choisissez un mouvement (w: haut, s: bas, a: gauche, d: droite) : ");
    scanf(" %c", &direction);

    int new_i = *pos_i, new_j = *pos_j;

    // Coordonées
    if (direction == 'w') new_i--;
    else if (direction == 's') new_i++;
    else if (direction == 'a') new_j--;
    else if (direction == 'd') new_j++;

    // Collisions
    if (board[new_i][new_j] == '#') {
        printf("Vous avez touché un mur !\n");
        return;
    }

    // Déplacements caisse
    if (new_i == *pos_ca && new_j == *pos_cb) {
        int new_ca = *pos_ca + (new_i - *pos_i);
        int new_cb = *pos_cb + (new_j - *pos_j);

        if (board[new_ca][new_cb] == '#' || board[new_ca][new_cb] == 'X') {
            printf("La caisse est bloquée , partie terminée !\n");
            exit(0);
        }

        // Déplacer la caisse
        board[*pos_ca][*pos_cb] = ' ';  
        *pos_ca = new_ca;               
        *pos_cb = new_cb;               
        board[*pos_ca][*pos_cb] = 'X';  
    }

    	// Déplacer le joueur
    	board[*pos_i][*pos_j] = ' ';  
    	*pos_i = new_i;               
    	*pos_j = new_j;               
    	board[*pos_i][*pos_j] = 'o';

        // Vérification de la victoire
        if (*pos_ca == pos_ga && *pos_cb == pos_gb) {
            display_board(board);
            printf("Bravo, vous avez gagné !\n");            
            exit(0);
        }
    

    board[*pos_i][*pos_j] = ' ';
    *pos_i = new_i;
    *pos_j = new_j;
    board[*pos_i][*pos_j] = 'o';
    // Cas contact Joueur - Goal
    if (*pos_i == pos_ga && *pos_j == pos_gb) {
        board[pos_ga][pos_gb] = '.';
    } else {
        board[pos_ga][pos_gb] = '.';
    }
    
    system("clear");
    display_board(board);

    // Partie perdue
    if (is_box_blocked(board, *pos_ca, *pos_cb)) {
        printf("La caisse est bloquée. Vous avez perdu !\n");        
        exit(0);
    }
}

int is_box_blocked(char **board, int pos_ca, int pos_cb) {
    if ((board[pos_ca - 1][pos_cb] == '#' || board[pos_ca - 1][pos_cb] == 'X') && // au-dessus
        (board[pos_ca + 1][pos_cb] == '#' || board[pos_ca + 1][pos_cb] == 'X') && // en dessous
        (board[pos_ca][pos_cb - 1] == '#' || board[pos_ca][pos_cb - 1] == 'X') && // à gauche
        (board[pos_ca][pos_cb + 1] == '#' || board[pos_ca][pos_cb + 1] == 'X')) {  // à droite
        return 1;
    }
    return 0;
}