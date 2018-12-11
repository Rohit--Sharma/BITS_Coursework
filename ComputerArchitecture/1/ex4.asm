#The instructions for declaring an integer array of size 4
		.data			#variable declaration follow this line
array1:	.space 16 		#declare 16 bytes of storage to hold
						#array of 4 integers
lbrk:	.ascii "\n"				
						
		.text
main:	la $t0, array1	#load base address of array into
						#register $t0
		li $s0, 5
		sw $s0, 0($t0)
		li $s0, 10
		sw $s0, 4($t0)
		li $s0, 15
		sw $s0, 8($t0)
		li $s0, 20
		sw $s0, 12($t0)			
		
		lw $s1, 0($t0)
		sw $s0, 0($t0)
		sw $s1, 12($t0)
		
	#assume the base address of the array is stored in $t0
		li $v0, 1 		#load appropriate system call into register v0
		lw $a0, 0($t0)
		syscall	
		
		li $v0, 4		#print new line
		la $a0, lbrk
		syscall
		
		li $v0, 1		#print 2nd int
		lw $a0, 4($t0)
		syscall
		
		li $v0, 4		#print new line
		la $a0, lbrk
		syscall
		
		li $v0, 1		#print 3rd int
		lw $a0, 8($t0)
		syscall
		
		li $v0, 4		#print new line
		la $a0, lbrk
		syscall
		
		li $v0, 1		#print 4th int
		lw $a0, 12($t0)
		syscall	
		
		li $v0, 10
		syscall				
