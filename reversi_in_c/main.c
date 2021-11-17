#include "reversi.h"

/**
 * main - Used all functions for reversi working. Demand of player to
 * add a new piece
 *
 * Return: 0 if the program is sucess
 */
int main(void)
{
	char **reversi;

	reversi = reversi_init();

	print_table_reversi(reversi);

	reversi_free(reversi);

	return (0);
}
