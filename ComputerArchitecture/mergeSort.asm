		.data
arrA:	.space	80
arrB:	.space	80
sorted:	.space	160

promptn1:	.asciiz	"Input number of elements in first array:\n"
pmtNum1:	.asciiz	"Input "
pmtNum2:	.asciiz	" integers\n"
promptn2:	.asciiz	"Input number of elements in second array:\n"
answer:		.asciiz	"Sorted array:\n"
newLine:	.asciiz	"\n"

		.text
main:

	la $a0, promptn1
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $t0, $v0					# $t0 = m
	
	la $a0, pmtNum1
	li $v0, 4
	syscall
	move $a0, $t0
	li $v0, 1
	syscall
	la $a0, pmtNum2
	li $v0, 4
	syscall
	
	la $t1, arrA					# $t1 points to arrA
	li $s0, 0						# $s0 is loop iterator (i = 0)
	sll $t2, $t0, 2					# $t2 = size
	readInput1:						# dummy label, not used anywhere
		bge $s0, $t2, readInputDone1# if(i >= m) break;
		
		li $v0, 5
		syscall
		sw $v0, 0($t1)
		
		addi $s0, $s0, 4 			# i++
		la $t1, arrA
		add $t1, $t1, $s0
		
		j readInput1
		
	readInputDone1:
	
	la $a0, promptn2
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $t3, $v0					# $t3 = n
	
	la $a0, pmtNum1
	li $v0, 4
	syscall
	move $a0, $t3
	li $v0, 1
	syscall
	la $a0, pmtNum2
	li $v0, 4
	syscall
	
	la $t1, arrB					# $t1 points to arrB
	li $s0, 0						# $s0 is loop iterator (i = 0)
	sll $t4, $t3, 2					# $t4 = size
	readInput2:						# dummy label, not used anywhere
		bge $s0, $t4, readInputDone2# if(i >= n) break;
		
		li $v0, 5
		syscall
		sw $v0, 0($t1)
		
		addi $s0, $s0, 4 			# i++
		la $t1, arrB
		add $t1, $t1, $s0
		
		j readInput2
		
	readInputDone2:
	
	add $t5, $t4, $t2				# $t5 = size
	
	jal merge
	
	la $a0, answer
	li $v0, 4
	syscall
	
	la $t1, sorted					# $t1 points to sorted
	li $s0, 0						# $s0 is loop iterator (i = 0)
	
	printOutput:					# dummy label, not used anywhere
		bge $s0, $t5, printOpDone	# if(i >= n) break;
		
		lw $a0, 0($t1)
		li $v0, 1
		syscall
		la $a0, newLine
		li $v0, 4
		syscall
		
		addi $s0, $s0, 4 			# i++
		la $t1, sorted
		add $t1, $t1, $s0
		
		j printOutput
	printOpDone:
	
exit:
	li $v0, 10
	syscall	
	
merge:
	add $sp, $sp, -4
	sw $ra, 0($sp)
	
	li $s1, 0						# $s1 = i, i=0 
	li $s2, 0						# $s2 = j, j=0 
	li $s3, 0						# $s3 = k, k=0 
	la $t6, arrA
	la $t7, arrB
	la $t8, sorted
	
	loop:
		bge $s1, $t5, loopDone		# if (i >= m+n) break;
	
		slt $s4, $s2, $t2
		slt $s5, $s3, $t4
		add $s4, $s5, $s4
		li $s5, 2
		bne $s4, $s5, label
			add $a1, $t6, $s2
			add $a2, $t7, $s3
			lw $a1, 0($a1)
			lw $a2, 0($a2)
			bge $a1, $a2, label2
				add $a1, $t8, $s1
				add $a2, $t6, $s2
				lw $a2, 0($a2)
				sw $a2, 0($a1)
				addi $s2, $s2, 4
				j label11
			label2:
				add $a1, $t8, $s1
				add $a2, $t7, $s3
				lw $a2, 0($a2)
				sw $a2, 0($a1)
				addi $s3, $s3, 4
			label11:
			addi $s1, $s1, 4
			j loop3Done	
		label:
		bne $s2, $t2, label3
			loop2:
				bge $s1, $t5, loop2Done
				add $a1, $t8, $s1
				add $a2, $t7, $s3
				lw $a2, 0($a2)
				sw $a2, 0($a1)
				addi $s3, $s3, 4
				addi $s1, $s1, 4
				j loop2
			loop2Done:
			j loop3Done
		label3:
			loop3:
				bge $s1, $t5, loop3Done
				add $a1, $t8, $s1
				add $a2, $t6, $s2
				lw $a2, 0($a2)
				sw $a2, 0($a1)
				addi $s2, $s2, 4
				addi $s1, $s1, 4
				j loop3
			loop3Done:
		j loop
	loopDone:
	
	lw $ra, 0($sp)	
	add $sp, $sp, 4
	jr $ra
	
#used reg: $t0, $t1, $t2, $s0, $t3, $t4, $t5, $s1, $s2, $s3, $s4, $s5, $t6, $t7, $t8	
