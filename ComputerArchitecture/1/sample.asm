#objective of the program is to add 5 and 7
	.data					#variable declaration follow this line
	.text					#instructions follow this line
main:					
	ori $s0, $zero, 0x6
	ori $s1, $zero, 0x8
	add $t0, $s0, $s1
	li $v0, 1				# load 1 into v0 to print integer
	add $a0, $t0, $zero		# move the value to be printed to a0
	syscall
	li $v0,10			 	# load 10 into v0 to exit
	syscall					# required for only QtSPIM
	#end of program
