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

	test_position(reversi, line, column, color);
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
 * test_position - Test if the position asking by the player is avaible
 * If it avaible, call another functions to place the piece and convert
 * all pieces
 *
 * @reversi: The reversi table
 * @line: The index of the line asking by the player
 * @column: The index of the column asking by the player
 * @color: The color of the player
 */
void test_position(char **reversi, int line, int column, char color)
{
	char color_ia;
	int i = 0;

	if (color == 'W')
		color_ia = 'B';
	else
		color_ia = 'W';

	if (reversi[line - 1][column - 1] == color_ia)
		i += diag_high_left(reversi, line, column, color);
	/*else if (reversi[line - 1][column] == color_ia)
		hor_high;
	else if (reversi[line - 1][column + 1] == color_ia)
		diag_high_right;
	else if (reversi[line][column - 1] == color_ia)
		ver_left;
	else if (reversi[line][column + 1] == color_ia)
		ver_right;
	else if (reversi[line + 1][column - 1] == color_ia)
		diag_down_left;
	else if (reversi[line + 1][column] == color_ia)
		hor_down;
	else if (reversi[line + 1][column + 1] == color_ia)
		diag_down_right;*/

	if (i == 0)
	{
		printf("The position is not valid, no piece around\n");
		ask_to_player(reversi, color);
	}
}
