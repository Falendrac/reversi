#include "reversi.h"

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
