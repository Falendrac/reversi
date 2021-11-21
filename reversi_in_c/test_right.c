#include "reversi.h"

/**
 * test_diag_high_right - Test if the diagonal high right
 * is possible for the player
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @column: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the diag have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_diag_high_right(char **reversi, int line, int column, char color)
{
	while (line > 1 && column < 8 && reversi[line][column] != color)
	{
		line--;
		column++;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}

/**
 * test_ver_right - Test if the vertical right is possible for the player
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @column: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the ver have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_ver_right(char **reversi, int line, int column, char color)
{
	while (column < 8 && reversi[line][column] != color)
	{
		column++;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}

/**
 * test_hor_down - Test if the horizontal down is possible for the player
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @column: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the hor have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_hor_down(char **reversi, int line, int column, char color)
{
	while (line < 8 && reversi[line][column] != color)
	{
		line++;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}

/**
 * test_diag_down_right - Test if the diagonal down right
 * is possible for the player
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @column: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the diag have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_diag_down_right(char **reversi, int line, int column, char color)
{
	while (line < 8 && column < 8 && reversi[line][column] != color)
	{
		line++;
		column++;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}
