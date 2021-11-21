#include "reversi.h"

/**
 * test_diag_high_left - Test if the diagonal high left is
 * possible for the player
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @column: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the diag have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_diag_high_left(char **reversi, int line, int column, char color)
{
	while (line > 1 && column > 1 && reversi[line][column] != color)
	{
		line--;
		column--;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}

/**
 * test_hor_high - Test if the horizontal high is possible for the player
 *
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @column: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the hor have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_hor_high(char **reversi, int line, int column, char color)
{
	while (line > 1 && reversi[line][column] != color)
	{
		line--;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}

/**
 * test_ver_left - Test if the vertical left is possible for the player
 *
 * @reversi: The reversi table
 * @line: The index of line asking by the player
 * @column: The index of column asking by the player
 * @color: Color of the player
 *
 * Return: 0 if the ver have not the same color in the last test
 * 1 if the position is a correction position for the player
 */
int test_ver_left(char **reversi, int line, int column, char color)
{
	while (column > 1 && reversi[line][column] != color)
	{
		column--;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}

/**
 * test_diag_down_left - Test if the diagonal down left
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
int test_diag_down_left(char **reversi, int line, int column, char color)
{
	while (line < 8 && column > 1 && reversi[line][column] != color)
	{
		line++;
		column--;
	}

	if (reversi[line][column] != color)
		return (0);

	return (1);
}
