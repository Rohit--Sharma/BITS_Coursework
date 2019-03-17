#Artificial Intelligence (Assignment 1)

## Chess Bot using Minimax Algorithm

-----------------------
**GENERAL USAGE NOTES**
-----------------------

- Recommended to run the program in linux environment.
- Utility value for a board configuration is calculated as follows:
	(Only for alive pawns)
	Total distance moved + No. of forward moves possible + 4 * captures - 2 * deaths

------------
**INCLUDED**
------------
Source code: 	chess.cpp
Executable: 	chess

------------------------
**RUNNING INSTRUCTIONS**
------------------------

Run the following commands in the terminal after navigating to the directory in which the source files are present:
Compiling: 
$ g++ chess.cpp -o chess
Executing:
$ ./chess

---------------
**HOW TO PLAY**
---------------

The computer moves first and is White.
Player and Computer take alternate turns.
For making a move, the player is to enter four space separated coordinates: si sj ei ej
- si -> initial row number
- sj -> initial column number
- ei -> final row number
- ej -> final column number

The color which successfully takes one of its pawn to the last row of opponent wins.
If no move is possible for a player the game is declared draw.

Any queries can be addressed to _f2012009@hyderabad.bit-pilani.ac.in_
Any queries can be addressed to _f2012056@hyderabad.bit-pilani.ac.in_

