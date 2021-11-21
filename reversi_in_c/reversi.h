#ifndef REVERSI_H
#define REVERSI_H

#include <stdio.h>
#include <stdlib.h>

void print_table_reversi(char **reversi);
void get_full_reversi(char **reversi);
char **reversi_init(void);
void reversi_free(char **reversi);

void ask_to_player(char **reversi, char color);
char ask_color(void);
void test_position(char **reversi, int line, int column, char color);

int diag_high_left(char **reversi, int line, int column, char color);

#endif
