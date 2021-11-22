#include "reversi.h"

/**
 * ask_to_player - Ask to player what position he want to place a piece
 *
 * @reversi: The reversi table
 * @color: Color of the player
 */
void ask_to_player(char **reversi, char color)
{
	char *str;
	int line, column;

	str = malloc(sizeof(char) + (3));
	*(str + 2) = '\0';
	printf("Give the position you want to place your piece (like 1A):\n");
	scanf("%s", str);

	if (*str < '1' || *str > '8' || *(str + 1) < 'A' || *(str + 1) > 'H')
	{
		printf("You don't give a right position. Please respect the format 1A.\n");
		free(str);
		ask_to_player(reversi, color);
		return;
	}

	line = *str - 48;
	column = *(str + 1) - 64;
	free(str);

	if (reversi[line][column] != ' ')
	{
		printf("The position you give is not empty. Please give another position\n");
		ask_to_player(reversi, color);
		return;
	}

	convert_position(reversi, line, column, color);
}

/**
 * ask_color - Ask to the player what color he want
 *
 * Return: The color of the player
 */
char ask_color(void)
{
	char color;

	printf("Choose your color (W or B):\n");
	scanf("%c", &color);

	if (color != 'W' && color != 'B')
	{
		printf("You put a wrong color please choose W or B:\n");
		return (ask_color());
	}

	return (color);
}

/**
 * convert_position - Test if the position asking by the player is avaible
 * If it avaible, call another functions to place the piece and convert
 * all pieces
 *
 * @reversi: The reversi table
 * @line: The index of the line asking by the player
 * @column: The index of the column asking by the player
 * @color: The color of the player
 */
void convert_position(char **reversi, int line, int column, char color)
{
	char color_ia;
	int i = 0;

	if (color == 'W')
		color_ia = 'B';
	else
		color_ia = 'W';

	reversi[line][column] = color;

	if (reversi[line - 1][column - 1] == color_ia)
		i += conver_dir(reversi, line - 1, column - 1, -1, -1, color);
	if (reversi[line - 1][column] == color_ia)
		i += conver_dir(reversi, line - 1, column, -1, 0, color);
	if (column < 8 && reversi[line - 1][column + 1] == color_ia)
		i += conver_dir(reversi, line - 1, column + 1, -1, 1, color);
	if (reversi[line][column - 1] == color_ia)
		i += conver_dir(reversi, line, column - 1, 0, -1, color);
	if (column < 8 && reversi[line][column + 1] == color_ia)
		i += conver_dir(reversi, line, column + 1, 0, 1, color);
	if (line < 8 && reversi[line + 1][column - 1] == color_ia)
		i += conver_dir(reversi, line + 1, column - 1, 1, -1, color);
	if (line < 8 && reversi[line + 1][column] == color_ia)
		i += conver_dir(reversi, line + 1, column, 1, 0, color);
	if (line < 8 && column < 8 && reversi[line + 1][column + 1] == color_ia)
		i += conver_dir(reversi, line + 1, column + 1, 1, 1, color);

	if (i == 0)
	{
		printf("The position is not valid, no piece around\n");
		reversi[line][column] = ' ';
		ask_to_player(reversi, color);
	}
}

/**
 * test_position - Test if the position asking by the player is avaible
 *
 * @reversi: The reversi table
 * @line: The index of the line asking by the player
 * @column: The index of the column asking by the player
 * @color: The color of the player
 *
 * Return: i, i is equal of 0 if we don't have valid positions
 */
int test_position(char **reversi, int line, int column, char color)
{
	char color_ia;
	int i = 0;

	if (reversi[line][column] != ' ')
		return (0);

	if (color == 'W')
		color_ia = 'B';
	else
		color_ia = 'W';

	if (reversi[line - 1][column - 1] == color_ia)
		i += test_dir(reversi, line - 1, column - 1, -1, -1, color);
	if (reversi[line - 1][column] == color_ia)
		i += test_dir(reversi, line - 1, column, -1, 0, color);
	if (column < 8 && reversi[line - 1][column + 1] == color_ia)
		i += test_dir(reversi, line - 1, column + 1, -1, 1, color);
	if (reversi[line][column - 1] == color_ia)
		i += test_dir(reversi, line, column - 1, 0, -1, color);
	if (column < 8 && reversi[line][column + 1] == color_ia)
		i += test_dir(reversi, line, column + 1, 0, 1, color);
	if (line < 8 && reversi[line + 1][column - 1] == color_ia)
		i += test_dir(reversi, line + 1, column - 1, 1, -1, color);
	if (line < 8 && reversi[line + 1][column] == color_ia)
		i += test_dir(reversi, line + 1, column, 1, 0, color);
	if (line < 8 && column < 8 && reversi[line + 1][column + 1] == color_ia)
		i += test_dir(reversi, line + 1, column + 1, 1, 1, color);

	if (i != 0)
		printf("%d%c\n", line, column + 'A' - 1);

	return (i);
}

/**
 * valid_position - Test if the position asking by the player is avaible
 *
 * @reversi: The reversi table
 * @color: The color of the player
 *
 * Return: i, i is equal of 0 if we don't have valid positions
 */
int valid_position(char **reversi, char color)
{
	int loopX, loopY, i = 0;

	printf("Valid position for a %c piece:\n", color);

	for (loopX = 1; loopX < 9; loopX++)
		for (loopY = 1; loopY < 9; loopY++)
			i += test_position(reversi, loopX, loopY, color);

	if (i == 0)
		printf("No position for %c piece\n", color);

	return (i);
}
