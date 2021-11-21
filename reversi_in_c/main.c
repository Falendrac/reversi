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

	two_players(reversi);

	reversi_free(reversi);

	return (0);
}

void two_players(char **reversi)
{
	char color;
	int i = 1;

	color = ask_color();

	while (i != 0)
	{
		i = valid_position(reversi, color);
		ask_to_player(reversi, color);
		print_table_reversi(reversi);

		if (color == 'W')
			color = 'B';
		else
			color = 'W';
	}
}
