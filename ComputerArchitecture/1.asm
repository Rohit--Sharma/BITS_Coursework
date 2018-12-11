		.data
prompt1: .asciiz "Enter 'm' value: "
answer: .asciiz "The result of the recursive function is: "

		.text
main:

	la $a0,prompt1
	li $v0,4
	syscall
	li $v0, 5
	syscall
	move $t0, $v0				#$t0 = m
	
	la $a0,answer
	li $v0,4
	syscall
	move $a1, $t0				#$a1 = m
	li $t2, 1
	jal recursive
	
	move $a0, $v0				#$a0 = result of function call
	li $v0, 1
	syscall
	
exit:
	li $v0, 10
	syscall
	
recursive:
	addi $sp, $sp, -8 			# adjust stack for 2 items
	sw $ra, 4($sp) 				# save return address
	sw $a1, 0($sp) 				# save argument
	
	
	slti $t1, $a1, 2 			# test for m < 2
	beq $t1, $zero, L1
	addi $v0, $a1, 1 			# if so, result is m + 1
	
	move $t3, $v0
	
	addi $sp, $sp, 8 			# pop 2 items from stack
	jr $ra 						# and return
	
	L1:
	
	addi $a1, $a1, -1 			# else decrement m
	#move $t3, $t2
	jal recursive 				# recursive call
	
	#move $t3, $t2
	move $t2, $v0
	
	lw $a1, 0($sp)				# restore original m
	addi $a1, $a1, -2			# rec(m-2)
	jal recursive
	
	move $t2, $t3
	lw $ra, 4($sp) 				# and return address
	addi $sp, $sp, 8 			# pop 2 items from stack
	mul $v0, $t2, $v0 			# multiply to get result
	jr $ra 						# and return
