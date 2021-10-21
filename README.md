# Reversi

## General

Here, you can find my personnal project to develop the reversi game with the most languages. In first, i develop the reversi with the C language and later i go make other reversi but with differents languages.
Description of Reversi comming later.

## Requirements

For compiling:
> gcc -Wall -pedantic -Werror -Wextra -std=gnu89 [NAMEOFFILE.c] -o [NEWFILE]

Using Ubuntu 20.04.

## Algorithm

Currently is the first "jet" of my algorithm for the reversi.

1. Create an bi-dimenssionnal array of characters.

2. Initializing the array for : The first line have 'A' to 'H' characters ; The first column have "1" to "8" characters ; 
The rest of the array have space character, except D-4, D-5, E-4 and E-5 positions where we have the firsts pieces of the game.

* Browse the array
    * Fill the first line of 'A' to 'H'
    * Fill the first column of '1' to '8'
    * Fill the rest of the array of space
    * Fill the center of the array with pieces. B for black and W for white to the position: [D,4]; [D,5]; [E-4]; [E-5]
* End Browse

3. Print the array

    * Browse the array
        * Print the current position of the array
    * End browse

4. Demand to the player, what color he want (Black or White)
    
    * Print: "What color do you want: W or B ?"
    * Input B or W

    * If the character is not B or W
        * Print: "Wrong color, please, insert B or W to choose your color"
        * Call again the function
    * Else
        * Return the color choosen by the player
    * End If

5. Demand to the player where he want to put theyr piece in the table

    * Print: "Where you want to put your piece ? Write: A to H and 1 to 8. Like: E6"
    * Input a string like [{A-H}{1-8}]: [E6]

    * If the string is a uncorrect position
        * Print: "This position is uncorrect please, put a correct position."
        * Call again the function
    * End If
    * If the position already have a piece
         * Print: "This position already have a piece, please put another position."
          * Call again the function
    * End If

    * Call a function that validate if a piece can be convert in Black or White

        * Browse in diagonal, line and column an other piece
            
            * If this is not have a valide piece around the position
                * Print: "This position don't have a possibilities to take an ennemy piece. Please, put another position."
                * recall te function to demand a new position
            * End If

            * If the position have a valide piece around the position
                * Put the piece in the array
                * Convert all the concern pieces
            * End If
        
        * End Browse
