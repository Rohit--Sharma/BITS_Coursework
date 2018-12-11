		.data
inp1:	.asciiz "Enter a: "	
inp2:	.asciiz "Enter b: "	
res:	.asciiz "GCD = "
		
		.text
main:

	li $v0, 4
	la $a0, inp1
	syscall	
	
	li $v0, 5
	syscall
	
	move $t7, $v0		#t7 = a
	
	li $v0, 4
	la $a0, inp2
	syscall	
	
	li $v0, 5
	syscall
	
	move $a0, $t7		#a0 = a
	move $a1, $v0		#a1 = b
	
	jal gcd
	
	move $t0, $v0		#t0 = gcd(a, b)
	
	li $v0, 4
	la $a0, res
	syscall	
	
	li $v0, 1
	move $a0, $t0
	syscall
	
exit:
	li $v0, 10
	syscall
	
gcd:
	addi $sp, $sp, -4	#storing address of nxt instruction
	sw $ra, 0($sp)		#on stack
	
	blt $a0, $a1, dwn
	move $s0, $a0
	move $a0, $a1
	move $a1, $s0
	
	dwn:
	div $a1, $a0
	mfhi $t3
	beq $t3, $zero, dd
	move $a1, $a0
	move $a0, $t3
	j dwn
	
	dd:
	move $v0, $a0
	
	lw $ra, 0($sp)		#popping address of nxt instruction
	addi $sp, $sp, 4	#from stack
	jr $ra		
