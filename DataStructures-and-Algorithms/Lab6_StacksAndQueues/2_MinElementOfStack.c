#include<stdio.h>
#include<stdlib.h>

int pos = 0;							//Current position in stack.
int n;									//Size of the stack obtained at run-time.

void push(int *a, int val) {
	if(!isFull(a, n))
		*(a + pos++) = val;
	else
		printf("Stack is full.\n");
}
int pop(int *a) {
	if(!isEmpty(a))
		return *(a + --pos);
	else {
		printf("Stack is empty.\n");
		return -1;
	}
}
int size(int *a) {
	return pos;
}
int isEmpty(int *a) {
	if(size(a) == 0) return 1;
	else return 0;
}
int isFull(int *a, int sz) {
	if(size(a) == sz) return 1;
	else return 0;
}

int main() {
	int i, k; scanf("%d", &n);
	int *stk = malloc(sizeof(int)*n);	//Array implementation of stack.
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		push(stk, k);
	}
	//push(stk, 10);					//If uncommented this line, error message prompting "stack is full" will be displayed.
	//for(i=0; i<n; i++) {
	//	printf("%d", *(stk+i));
		//k = pop(stk);
		//printf("%d ", k);
	//}
	//pop(stk);							//If uncommented this line, error message prompting "stack is empty" will be displayed.
	printf("\n");
	int min=pop(stk);
	int *minstk = malloc(sizeof(int)*n);
	push(minstk, min);
	for(i=1; i<n; i++) {
		k = pop(stk);
		if(k < min) push(minstk, (min = k));
	}
	printf("Min = %d\n", pop(minstk));
	return 0;
}
