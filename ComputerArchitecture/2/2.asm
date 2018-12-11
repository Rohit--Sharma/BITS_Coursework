		.data
p: .asciiz "Palindrome"
np: .asciiz "Not palindrome"		
string1: .space 1024

		.text
main:
	li $v0, 8
	la $a0, string1
	li $a1, 1024
	syscall

	la $t1, string1
	lb $t2, 0($t1)

	li $t5, 0
	li $t4, 0
	loop:
		beq $t2, $zero, down
		addu $t5, $t5, 1
		addu $t1, $t1, 1
		lb $t2, 0($t1)
	j loop
	
down:
	subu $t5, $t5, 1
	#srl $t5, $t5, 1
	
	la $t1, string1
	la $t3, string1
	addu $t3, $t3, $t5
	subu $t3, $t3, 1
	lb $t2, 0($t1)
	lb $t6, 0($t3)
	li $t7, 0
	
	loo:
		bne $t2, $t6, notPal
		addu $t1, $t1, 1
		subu $t3, $t3, 1
		addu $t7, $t7, 1
		lb $t2, 0($t1)
		lb $t6, 0($t3)
		beq $t7, $t5, pal
	j loo
	
pal:
	la $a0, p
	li $v0, 4
	syscall	
	j exit
	
notPal:
	la $a0, np
	li $v0, 4
	syscall	
	j exit
	
#down:
#	move $a0, $t5
#	li $v0, 1
#	syscall


exit:
	li $v0, 10
	syscall
