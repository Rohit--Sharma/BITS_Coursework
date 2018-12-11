		.data
str: 	.space 1024
cha:	.space 2
cha1:	.space 2
cha2: 	.space 2
table:	.word 0, 0, 0
len:	.asciiz "Length of the string: "
pr1:	.asciiz "Enter a character: "
pr2:	.asciiz "Enter a character you want to replace: "
pr3:	.asciiz "\nEnter a character you want to replace with: "
freq:	.asciiz "\nFrequency of the character: "
repl:	.asciiz "\nString after replacing the character: "
inp1:	.asciiz "Enter a string: "
inp2:	.asciiz "Enter a case: \n0: Find length of string.\n1: Find frequency of a character.\n2: Replace a character.\n"

		.text
main:
	
	li $v0, 4
	la $a0, inp1
	syscall
	
	li $v0, 8
	la $a0, str
	li $a1, 1024
	syscall
	
	li $v0, 4
	la $a0, inp2
	syscall
	
	li $v0, 5
	syscall
	move $t2, $v0
	mul $t2, $t2, 4
	
	j down
	
case0:
		li $t4, -1	
		la $t0, str
	loop:
		lb $t3, 0($t0)
		beq $t3, $zero, out
		addi $t4, $t4, 1
		addi $t0, $t0, 1
		j loop

	out:
		li $v0, 4
		la $a0, len
		syscall
		
		li $v0, 1
		move $a0, $t4
		syscall
		
		j exit	

case1:
		li $v0, 4
		la $a0, pr1
		syscall
		
		li $v0, 8
		la $a0, cha
		li $a1, 2
		syscall
		
		li $t4, 0
		la $t0, str
		lb $t7, cha
	lo:
		lb $t3, 0($t0)
		beq $t3, $zero, ou
		bne $t3, $t7, na
		addi $t4, $t4, 1
		na:
		addi $t0, $t0, 1
		j lo	
	
	ou:
		li $v0, 4
		la $a0, freq
		syscall
		
		li $v0, 1
		move $a0, $t4
		syscall
			
		j exit

case2:
		li $v0, 4
		la $a0, pr2
		syscall
		
		li $v0, 8
		la $a0, cha1
		li $a1, 2
		syscall
		
		li $v0, 4
		la $a0, pr3
		syscall
		
		li $v0, 8
		la $a0, cha2
		li $a1, 2
		syscall
		
		la $t0, str
		lb $t7, cha1
		lb $t8, cha2
	lo1:
		lb $t3, 0($t0)
		beq $t3, $zero, outt
		bne $t3, $t7, neq
		sb $t8, 0($t0)
		neq:
		addi $t0, $t0, 1
		j lo1
		
	outt:
		li $v0, 4
		la $a0, repl
		syscall
		
		li $v0, 4
		la $a0, str
		syscall		
		
		
		j exit

down:	
	la $t0, case0
	sw $t0, table
	
	la $t0, case1
	sw $t0, table+4
	
	la $t0, case2
	sw $t0, table+8
	
	la $s0, table
	add $s0, $s0, $t2	
	lw $t3, 0($s0)
	jr $t3
	
exit:
	li $v0, 10
	syscall			
