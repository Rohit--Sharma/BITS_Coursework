/*
 * TOC_Assignment.c
 * This file is part of "Theory of Computation Assignment-1"
 *
 * Copyright (C) 2014 - Rohit Kumar Sharma
 * 			   ID no. - 2012A7PS050H
 *
 * Problem statement:
 *		For the set of strings over {a,b}, where the first symbol in the input is same 
 *		as the third, fifth, and so on. i.e., the all the symbols in the odd numbered 
 *		positions are same.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype of a state
typedef struct state
{
	enum{Q0, Q1, Q2, Q3, Q4, D} label;
	struct state *on_a;
	struct state *on_b;
	enum{NO, YES} isFinal;
} state;

// Starting state, initialised to null and made global to get access in verify() function
state *q0 = NULL;

// Creates state transition table, which is a data structure containing states and transitions
//		to take on each symbol read
createTransitionTable()
{
	// Allocate memory to starting state and all other states in the transition table
	q0 = malloc(sizeof(state));
	state *q1 = malloc(sizeof(state));
	state *q2 = malloc(sizeof(state));
	state *q3 = malloc(sizeof(state));
	state *q4 = malloc(sizeof(state));
	state *d = malloc(sizeof(state));
	
	// Fill information regarding each state like the label, the transition to take if 'a' or 'b'
	//		is read, and the information if the state is final state or not
	{
		q0->label = Q0;					// q0 is the structure reference and Q0 
		q0->on_a = q1;					// is the actual label used for 
		q0->on_b = q3;					// printing
		q0->isFinal = NO;

		q1->label = Q1;
		q1->on_a = q2;
		q1->on_b = q2;
		q1->isFinal = YES;				// q1 is final state

		q2->label = Q2;
		q2->on_a = q1;
		q2->on_b = d;
		q2->isFinal = YES;				// q2 is final state

		q3->label = Q3;
		q3->on_a = q4;
		q3->on_b = q4;
		q3->isFinal = YES;				// q3 is final state

		q4->label = Q4;
		q4->on_a = d;
		q4->on_b = q3;
		q4->isFinal = YES;				// q4 is final state

		d->label = D;					// D stands for dead state
		d->on_a = d;					// and takes transition to d itself 
		d->on_b = d;					// upon reading any symbol from now
		d->isFinal = NO;				// Dead state is not a final state
	}
}

// Utility function which returns the label of the state stt as a char pointer
char *getLabel(state *stt)
{
	char *st = malloc(sizeof(char) * 3);			// Allocate memory for a string of length 3
	
	// Initialise the string with desired state name depending on the label
	switch(stt->label) {
		case 0: strcpy(st, "Q0"); break;
		case 1: strcpy(st, "Q1"); break;
		case 2: strcpy(st, "Q2"); break;
		case 3: strcpy(st, "Q3"); break;
		case 4: strcpy(st, "Q4"); break;
		case 5: strcpy(st, "D"); break;
		default: perror("Switch"); exit(-1);		// If the label is other than the above specified, it is an error
	}
	
	// Return the pointer to the string
	return st;
}

// This function uses the transition table created in createTransitionTable() function to verify if
// 	string pointed by s is accepted or not
verify(char *s)
{
	int i;											// Loop iterator
	state *current = malloc(sizeof(state));			// A variable to store current state and changes in every iteration of loop
	current = q0;									// Initialise current to q0 which is starting state
	char *st;										// A char pointer which will contain the name of the state 
	
	// Iterate through the entire string
	for (i = 0; i < strlen(s); i += 1) {
	
		//Printing configuration
		st = getLabel(current);
		printf("\t(%s, %s)\n", st, s+i);
		
		if(*(s+i) == 'a') {							// Take a transition to one of the states
			current = current->on_a;				// 	specified by either "current->on_a"
		} else if(*(s+i) == 'b') {					// 	or "current->on_b" if the symbol read
			current = current->on_b;				// 	is 'a' or 'b' respectively
		} else {
			perror("Invalid string");				// If a character other than 'a' or 'b'
			exit(-1);								//  is read, report error and exit
		}
			
	}
	
	//Printing configuration
	st = getLabel(current);							// Print the final state
	printf("\t(%s, %s)\n", st, "e");					// 	and unread string as 'e' since all the string has been read
		
	// Finally accept or reject the string
	if (current->isFinal == YES) {					// If the last state is final,
		printf("\n\nThe string \"%s\" is ACCEPTED\n", s);						//	then accept the string
	} else if (current->isFinal == NO) {			// else,
		printf("\n\nThe string \"%s\" is REJECTED\n", s);						//	reject the string
	}
}

//The main method
int main (int argc, char *argv[])
{
	// Check if there are two command line arguments and if not print the error message
	if(argc != 2) {
		printf("Usage: \n./a.out \"Input String\"\n");
		exit(-1);
	}
	
	system("clear");								// Using 'clear' system call to clear the screen and improve the visual
	
	printf("--------------------------------------------------------------------------------\n");
	printf("\t\t\tDETERMINISTIC FINITE AUTOMATA\n");
	printf("--------------------------------------------------------------------------------\n\n\n");
	
	printf("Printing configurations after every iteration:\n");
	// Create transition table for given question
	createTransitionTable();
	
	// Verify string passed in command line arguments to see if it is accepted or not.
	verify(argv[1]);
	
	printf("--------------------------------------------------------------------------------");
	getchar();
	return 0;
}
