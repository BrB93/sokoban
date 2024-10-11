#ifndef SOKOBAN_H
#define SOKOBAN_H

char **init_board();
void display_board(char **board);
void move_player(char **board, int *player_x, int *player_y);

#endif