		.data
nl: .asciiz "\n"

		.text	
main:

	li $v0, 5
	syscall
	ble $v0, $zero, exit
	move $t0, $v0

	li $v0, 5
	syscall
	ble $v0, $zero, exit
	move $t1, $v0

	li $t2, 1

	loop:
		mul $a0, $t2, $t0
		addi $t2, $t2, 1
		li $v0, 1
		syscall
		la $a0, nl
		li $v0, 4
		syscall
		bgt $t2, $t1, exit
	j loop

exit:
	li $v0, 10
	syscall
