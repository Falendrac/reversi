#ifndef REVERSI_H
#define REVERSI_H

#include <stdio.h>
#include <stdlib.h>

void print_table_reversi(char **reversi);
void get_full_reversi(char **reversi);
char **reversi_init(void);
void reversi_free(char **reversi);

#endif
