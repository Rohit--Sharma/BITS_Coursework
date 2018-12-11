		.data
prompta: 	.asciiz "Enter the number a: "
promptb: 	.asciiz "Enter the number b: "		
answer: 	.asciiz "The perfect numbers are: \n"
count: 		.asciiz "The number of perfect numbers: "	
newline: 	.asciiz "\n"
	
		.text
main:

	la $a0,prompta
	li $v0,4
	syscall
	li $v0, 5
	syscall
	move $t7, $v0				#$t7 = a
	
	la $a0,promptb
	li $v0,4
	syscall
	li $v0, 5
	syscall
	move $t8, $v0				#$t8 = b
	
	la $a0,answer
	li $v0,4
	syscall
	move $a1, $t7				#$a0 = a
	move $a2, $t8				#$a1 = b
	jal perfect
	
	move $t0, $v0				#$t0 = return value of perfect() which is number of perfect numbers
	
	la $a0,count
	li $v0,4
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	
exit:
	li $v0, 10
	syscall
	
perfect:

	addi $sp, $sp, -4			#storing return address on stack
	sw $ra, 0($sp)
	
	#move $t1, $a0				#$t1 = a
	#move $t2, $a1				#$t2 = b
	li $s3, 0					#count of perfect no.s
	
	lab5:
	jal is_perfect
	beq $v0, $zero, lab3
	addi $s3, $s3, 1
	li $v0, 1
	move $a0, $a1
	syscall
	la $a0, newline
	li $v0,4
	syscall
	
	lab3:
	addi $a1, $a1, 1
	beq $a1, $a2, lab4
	j lab5
	
	lab4:
	move $v0, $s3
	
	lw $ra, 0($sp)				#popping return address
	addi $sp, $sp, 4			#from stack and
	jr $ra						#returning
	
is_perfect:
	
	addi $sp, $sp, -4			#storing return address on stack
	sw $ra, 0($sp)
	
	li $v0, 0
	
	li $s0, 2					#counter from 2 to a i.e., $a0
	addi $s1, $zero, 1			#stores sum of factors of $a0
	
	lab1:
	bge $s0, $a1, label
	div $a1, $s0
	mfhi $s2					#$s2 = $a0 % $s0
	bne $s2, $zero, lab
	add $s1, $s1, $s0
	lab:
	addi $s0, $s0, 1
	j lab1
	
	label:
	bne $s1, $a1, lab2
	li $v0, 1
	
	lab2:
	lw $ra, 0($sp)				#popping return address
	addi $sp, $sp, 4			#from stack and
	jr $ra						#returning
