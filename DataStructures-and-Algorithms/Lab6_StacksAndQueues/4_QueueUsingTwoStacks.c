#include<stdio.h>

int pos_en1=0, pos_de1=0, pos_en2=0, pos_de2=0;
int n;

void enqueue_1(int *a, int v) {
	if(!isFull(a, n))
		*(a + pos_en1++) = v;
	else
		printf("Queue is full!!!\n");
}
int dequeue_1(int *a) {
	if(!isEmpty(a))		
		return *(a + pos_de1++);
	else {
		printf("Queue is empty!!!\n");
		return -1;
	}
}
void enqueue_2(int *a, int v) {
	if(!isFull(a, n))
		*(a + pos_en2++) = v;
	else
		printf("Queue is full!!!\n");
}
int dequeue_2(int *a) {
	if(!isEmpty(a))		
		return *(a + pos_de2++);
	else {
		printf("Queue is empty!!!\n");
		return -1;
	}
}
void push(int *a, int val) {
	enqueue_1(a, val);
}
void pop(int *a, int *b, int sz) {
	int i;
	for(i=0; i<n-1; i++) {
		enqueue_2(b, *(a+i));
	}
	i=dequeue_2(b);
	return i;
}
int main() {
	
	return 0;
}
