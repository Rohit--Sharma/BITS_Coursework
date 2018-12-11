// Linked list implementation of stack

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *ptr;
}*top;
void push(int n) {
	struct node *t = malloc(sizeof(struct node));
	t->data = n;
	if(top == NULL) {
		top = t;
		top->ptr = NULL;
	}
	else {
		t->ptr = top;
		top = t;
	}
}
int pop() {
	int i = top->data;
	
}
int main() {
	int n, i, k;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		push(k);
	}
	for(i=0; i<n; i++) {
		printf("%d ", pop());
	}
	return 0;
}
