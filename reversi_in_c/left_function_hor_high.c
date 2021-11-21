#include "reversi.h"

/**
 * diag_high_left - Test if the diagonal high left is possible for the player
 * and convert all other piece in theyr color
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @color: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the diag have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int diag_high_left(char **reversi, int line, int column, char color)
{
	int line_search = line, column_search = column;

	while (line > 0 && column > 0 && reversi[line][column] != color)
	{
		line--;
		column--;
	}

	if (reversi[line][column] != color)
		return (0);

	while (line <= line_search && column <= column_search)
	{
		reversi[line][column] = color;
		line++;
		column++;
	}

	return (1);
}

/*hor_high;
ver_left;
diag_down_left;*/
