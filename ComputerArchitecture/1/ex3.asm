# objective of the program is to add constant 5 to each
# element of an array without using loop

		.data		#variable declaration follow this line
var1: 	.word 5		#one variable containing the value 5
array1:	.word 1,2	#declare 2 words of storage to
					#hold array of 2 integers
		
		.text		#instructions follow this line
main: 	lw $s1, var1	#load the variable var1 into $s1
		la $t0, array1	#load base address of array into
						#register $t0
		lw $s2, 0($t0)
		add $s2, $s2, $s1	#add var1 to the 1st element
							#of the array
		sw $s2, 0($t0)		#store the result into memory
		lw $s2, 4($t0)		
		add $s2, $s2, $s1	#add var1 to the second element
							#of the array
		sw $s2, 4($t0)

		li $v0, 10
		syscall