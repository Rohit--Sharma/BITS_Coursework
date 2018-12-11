	.data
p:	.asciiz "Is prime"
np:	.asxiiz "Not prime"

	.text
main:	
	li $v0, 5
	syscall
	
	move $s0, $v0
	li $t0, 2
	
loop:	
	rem $t1, $s0, $t0
	add $t0, $t0, 1
	beq $t0, $s0, prime
	beq $t1, $zero, nprime
	j loop
	
prime:
	li $v0, 4
	la $a0, p
	syscall
	j exit
			
nprime:
	li $v0, 4
	la $a0, np
	syscall
	
exit:
	li $v0, 10
	syscall				
