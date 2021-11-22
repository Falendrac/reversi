# Reversi in C

## General

Here you can find all source code for the reversi in C. I use all concepts 
i learn with Holberton School (except for one or two).

## Requirement

For compiling:

> gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o reversi

Ubuntu 20.04.

## How to play

Compile all .c files with gcc. Execute the program with ./reversi.

Give a color White or Black (W or B).
Give a position like 5F for example. And only the first character is a number in 1 to 8
and the second a letter in A to H.

Have fun.

### Source code

* array_handle.c

    File where we can find the functions for initializations of the array,
    print the array and free.

    Functions:

    * reversi_init(void)
    * get_full_reversi(char **reversi)
    * print_table_reversi(char **reversi)
    * reversi_free(char **reversi)

* direction_handle.c

    File where we can find the functions for browse all directions
    and convert pieces

    Functions:

    * test_dir(char **reversi, int li, int col, int difL, int difC, char color)
    * conver_dir(char **reversi, int li, int col, int difL, int difC, char color)

* playing.c

    File where we can find the functions for asking to the player
    what color he want, what position he want. Access to functions of direction.

    Functions:

    * ask_to_player(char **reversi, char color)
    * ask_color(void)
    * convert_position(char **reversi, int line, int column, char color)
    * test_position(char **reversi, int line, int column, char color)
    * valid_position(char **reversi, char color)

* main.c

    The main file, with the main function. Calling all others functions
    and start the game of reversi. Only one other function here for
    two players.

    Functions:

    * main(void)
    * two_players(char **reversi)

* main.h

    The header file with all prototype function of the reversi.
