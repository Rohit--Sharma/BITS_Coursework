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
	move $a0, $t5
	li $v0, 1
	syscall

exit:
	li $v0, 10
	syscall
