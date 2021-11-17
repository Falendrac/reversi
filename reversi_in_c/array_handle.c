#include "reversi.h"

/**
 * reversi_init - Initialise a double array for the reversi table
 * allocate dynamicly the array
 *
 * Return: **reversi with the piece in the table if the malloc is succes,
 * NULL if the malloc failled
 */
char **reversi_init(void)
{
	char **reversi;
	int loop;

	reversi = malloc(sizeof(char *) * (9 + 1));

		if (reversi == NULL)
			return (NULL);

		reversi[9] = '\0';

	for (loop = 0; loop < 9; loop++)
	{
		*(reversi + loop) = malloc(sizeof(char) * (9 + 1));

		if (*(reversi + loop) == NULL)
		{
		for ( ; loop >= 0; loop--)
			free(*(reversi + loop));
		free(reversi);
		return (NULL);
		}

		reversi[loop][9] = '\0';
}

	get_full_reversi(reversi);

	return (reversi);
}

/**
 * get_full_reversi - Fill the array with space and the firsts pieces
 * of the game. Fill the first line and column with the coordonate
 *
 * @reversi: The doublay array to fill with characters
 */
void get_full_reversi(char **reversi)
{
	int loopX, loopY;

	for (loopX = 0; loopX < 9; loopX++)
		for (loopY = 0; loopY < 9; loopY++)
		{
			if (loopX == 0 && loopY > 0)
				reversi[loopX][loopY] = 'A' + loopY - 1;
			else if (loopY == 0 && loopX > 0)
				reversi[loopX][loopY] = loopX + '0';
			else
				reversi[loopX][loopY] = ' ';
		}

	reversi[4][4] = 'B';
	reversi[4][5] = 'W';
	reversi[5][4] = 'B';
	reversi[5][5] = 'W';
}

/**
 * print_table_reversi - Print the table of the reversi
 *
 * @reversi: The double array cointaining the table
 */
void print_table_reversi(char **reversi)
{
	int loopX, loopY;

	for (loopX = 0; loopX < 9; loopX++)
	{
		for (loopY = 0; loopY < 9; loopY++)
		{
			putchar(reversi[loopX][loopY]);

			if (loopY != 8)
				printf(" | ");
		}

		putchar('\n');

		for (loopY = 0; loopY < 33; loopY++)
			putchar('=');

		putchar('\n');
		}
	}

/**
 * reversi_free - Free the memory allocated for reversi
 *
 * @reversi: The table we free of the memory
 */
void reversi_free(char **reversi)
{
	int loop;

	for (loop = 0; loop < 9; loop++)
		free(*(reversi + loop));

	free(reversi);
}
