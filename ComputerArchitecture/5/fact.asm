#sudo cp mips.lang /usr/share/gtksourceview-3.0/language-specs/ 
#sudo chmod 644 /usr/share/gtksourceview-3.0/language-specs/mips.lang

		.text
main:
	
	addi $a0, $zero, 4
	jal fact
	move $t0, $v0		#t0 = fact(a0)	
	
	li $v0, 1
	move $a0, $t0
	syscall
	
exit:
	li $v0, 10
	syscall
	
fact:	
	addi $sp, $sp, -8 # adjust stack for 2 items
	sw $ra, 4($sp) # save return address
	sw $a0, 0($sp) # save argument
	slti $t0, $a0, 1 # test for n < 1
	beq $t0, $zero, L1
	addi $v0, $zero, 1 # if so, result is 1
	addi $sp, $sp, 8 # pop 2 items from stack
	jr $ra # and return
	L1: addi $a0, $a0, -1 # else decrement n 
	jal fact # recursive call
	lw $a0, 0($sp) # restore original n
	lw $ra, 4($sp) # and return address
	addi $sp, $sp, 8 # pop 2 items from stack
	mul $v0, $a0, $v0 # multiply to get result
	jr $ra # and return
