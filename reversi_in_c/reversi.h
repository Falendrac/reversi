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
int test_position(char **reversi, int line, int column, char color);
void convert_position(char **reversi, int line, int column, char color);
int valid_position(char **reversi, char color);

void two_players(char **reversi);

int test_dir(char **reversi, int li, int col, int difL, int difC, char color);
int conver_dir(char **reversi, int li, int col, int difL, int difC, char color);

#endif
