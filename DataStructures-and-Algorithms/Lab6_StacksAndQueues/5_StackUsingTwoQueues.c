#include<stdio.h>
#include<stdlib.h>

int rear1=-1, front1=-1, rear2=-1, front2=-1, n;
	
enqueue(int *a, int val, int *rear, int *front) {
	if(*front==-1) (*front)++;
	(*rear)++;
	*(a+(*rear))=val;
}

int dequeue(int *a, int *rear, int *front) {
	int i;
	if(*front == *rear) {
		i=*(a+(*front));
		*front=*rear=-1;
	}
	else {
		i=*(a+(*front));
		(*front)++;
	}
	return i;
}

push(int *a, int *b, int val) {
	if(rear1>=n-1) {
		printf("Stack full\n");
	}
	else {
		if(front1==-1) {
			front1=rear1=0;
			*(a+rear1) = val;
		}
		else {
			enqueue(b, val, &rear2, &front2);
			while(front1<=rear1 && front1!=-1) {
				enqueue(b, dequeue(a, &rear1, &front1), &rear2, &front2);
			}
			while(front2<=rear2 && front2!=-1) {
				enqueue(a, dequeue(b, &rear2, &front2), &rear1, &front1);
			}
		}
	}
}

int pop(int *a) {
	if(front1==-1 || front1>rear1) {
		front1 = rear1 = -1;
		printf("Stack is empty.\n");
	}
	else {
		return dequeue(a, &rear1, &front1);
	}
}

int main() {
	scanf("%d", &n); int i, k;
	int *stack = malloc(sizeof(int)*n), *qu1 = malloc(sizeof(int)*n), *qu2 = malloc(sizeof(int)*n);
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		push(qu1, qu2, k);
	}
	for(i=0; i<n; i++) {
		printf("%d ", pop(qu1));
	} //pop(qu1);
	return 0;
}
