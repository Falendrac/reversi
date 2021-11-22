#include "reversi.h"

/**
 * test_dir - Test if the direction is
 * possible for the player
 *
 * @reversi: The reversi table
 * @li: The index of line asking by the player
 * @col: The index of column asking by the player
 * @difL: Where we go in line
 * @difC: Where we go in column
 * @color: Color of the player
 *
 * Return: 0 if the diag have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_dir(char **reversi, int li, int col, int difL, int difC, char color)
{
	char current = reversi[li][col];

	while ((li > 1 && li < 8) && (col > 1 && col < 8))
	{
		li += difL;
		col += difC;
		current = reversi[li][col];
		if (current == color || current == ' ')
			break;
	}

	if (reversi[li][col] != color)
		return (0);

	return (1);
}

/**
 * conver_dir - Test and convert all pieces in a direction
 *
 * @reversi: The reversi table
 * @li: The index of line asking by the player
 * @col: The index of column asking by the player
 * @difL: Where we go in line
 * @difC: Where we go in column
 * @color: Color of the player
 *
 * Return: 0 if the diag have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int conver_dir(char **reversi, int li, int col, int difL, int difC, char color)
{
	char current = reversi[li][col];
	int line_search = li, column_search = col;

	while ((li > 1 && li < 8) && (col > 1 && col < 8))
	{
		li += difL;
		col += difC;
		current = reversi[li][col];
		if (current == color || current == ' ')
			break;
	}

	if (reversi[li][col] != color)
		return (0);

	while (li != line_search || col != column_search)
	{
		reversi[li][col] = color;
		li -= difL;
		col -= difC;
	}

	reversi[li][col] = color;

	return (1);
}
