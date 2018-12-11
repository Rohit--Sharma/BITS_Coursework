#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top1=-1, top2=-1, n, *min;
push(int *a, int val, int *top1) {
		if(*top1==-1) {
			*(a+(++(*top1)))=val;
			push_min(min, val, &top2);
		}
		else {
			*(a+(++(*top1)))=val;
			if(top(min, &top2) > val)
				push_min(min, val, &top2);
			else
				push_min(min, top(min, &top2), &top2);
		}
}
push_min(int *min, int v, int *top2) {
		*(min+++(*top2)) = v;
}
int pop(int *a, int *top1) {
		return *(a+(*top1)--);
}
int top(int *a, int *top1) {
		return *(a+*(top1));
}
int isEmpty(int *top) {
	if(*top == -1) return 1;
	return 0;
}
int isFull(int *top) {
	if(*top>=n-1) return 1;
	return 0;
}
int main() {
	system("clear");
	printf("------PROGRAM TO FIND MINIMUM ELEMENT OF A STACK------\n\n\n\n");
	printf("\tSize of the stack: ");
	scanf("%d", &n);
	int i, *a = malloc(sizeof(int)*n), k; min = malloc(sizeof(int)*n);
	printf("\n\n\tElements: ");
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		push(a, k, &top1);
	}
	printf("\n\n\tMinimum: %d\n\n\n\tElements of the stack: ", pop(min, &top2));
	for(i=0; i<n; i++) {
		printf("%d ", pop(a, &top1));
	}
	
	printf("\n\n\n\n\n");
	return 0;
}
