#Artificial Intelligence (Assignment 1)

## A* search

-----------------------
**GENERAL USAGE NOTES**
-----------------------

- Recommended to run the program in linux environment.
- The heuristic fuction of a node is the minimum euclidean distance of any node reachable from this node scaled to 1.
_ex:_
for a 7x7 matrix
	for node (4, 5) with a = 0, b = 3
		h = 2/7^2
		
- The input file should be of the following format
	> First line should have the size of the grid, 'n'.
	> Next 'n' lines contain n comma seperated pairs of integers  indicating the 'a' and 'b' values of each cell as described in the problem seperated by tab
	> The destination node should be of the form 0, 0
- Sample test case:
4
0, 2	1, 2	-1, 1	0, 1
-1, 1	1, 2	1, 1	1, 2
0, 2	-1, 1	1, 1	0, 1
-1, 3	0, 1	-1, 2	0, 0

------------
**INCLUDED**
------------
Source code: 	FrogHop.cpp
Executable: 	frogHop

------------------------
**RUNNING INSTRUCTIONS**
------------------------

Run the following commands in the terminal after navigating to the directory in which the source files are present:
Compiling: 
$ g++ FrogHop.cpp -o frogHop
Executing:
$ ./frogHop < [InputFile]

Any queries can be addressed to _f2012050@hyderabad.bit-pilani.ac.in_
Any queries can be addressed to _f2012175@hyderabad.bit-pilani.ac.in_

