#ifndef __SOKOBAN__
#define __SOKOBAN__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


char ** init_board(int pos_i, int pos_j, int pos_ca, int pos_cb, int pos_ga, int pos_gb);
void display_board(char **board);
void move(char **board, int *pos_i, int *pos_j, int *pos_ca, int *pos_cb, int pos_ga, int pos_gb);
int is_box_blocked(char **board, int pos_ca, int pos_cb);

#endif