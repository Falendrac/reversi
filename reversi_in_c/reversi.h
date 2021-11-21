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

int diag_high_left(char **reversi, int line, int column, char color);
int hor_high(char **reversi, int line, int column, char color);
int ver_left(char **reversi, int line, int column, char color);
int diag_down_left(char **reversi, int line, int column, char color);

int diag_high_right(char **reversi, int line, int column, char color);
int ver_right(char **reversi, int line, int column, char color);
int hor_down(char **reversi, int line, int column, char color);
int diag_down_right(char **reversi, int line, int column, char color);

int test_diag_high_left(char **reversi, int line, int column, char color);
int test_hor_high(char **reversi, int line, int column, char color);
int test_ver_left(char **reversi, int line, int column, char color);
int test_diag_down_left(char **reversi, int line, int column, char color);

int test_diag_high_right(char **reversi, int line, int column, char color);
int test_ver_right(char **reversi, int line, int column, char color);
int test_hor_down(char **reversi, int line, int column, char color);
int test_diag_down_right(char **reversi, int line, int column, char color);

void two_players(char **reversi);

#endif
