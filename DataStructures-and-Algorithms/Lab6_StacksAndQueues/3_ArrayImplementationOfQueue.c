#include<stdio.h>
#include<stdlib.h>

int n;

int pos_en = 0, pos_de = 0;

void enqueue(int *a, int v) {
	if(!isFull(a, n))
		*(a + pos_en++) = v;
	else
		printf("Queue is full!!!\n");
}
int dequeue(int *a) {
	if(!isEmpty(a))		
		return *(a + pos_de++);
	else {
		printf("Queue is empty!!!\n");
		return -1;
	}
}
int isEmpty(int *a) {
	if(pos_en == pos_de) return 1;
	else return 0;
}
int isFull(int *a, int sz) {
	if(pos_en - pos_de == sz) return 1;
	else return 0;
}

int main() {
	int i, k; 
	system("clear");
	printf("Enter the size of the queue: ");
	scanf("%d", &n);
	int *queue = malloc(sizeof(int) * n);
	printf("Enter the elements: ");
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		enqueue(queue, k);
	}
	//enqueue(queue, 10);
	printf("The elements are: ");
	for(i=0; i<n; i++) {
		printf("%d ", dequeue(queue));
	}
	printf("\n");
	//dequeue(queue);
	return 0;
}
