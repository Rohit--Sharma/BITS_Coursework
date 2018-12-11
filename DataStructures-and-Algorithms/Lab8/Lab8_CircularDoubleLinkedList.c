#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int info;
	struct node *prev;
	struct node *next;
}node;

node *head = NULL, *tail = NULL;

insert(node **h, node **t, int val) 
{
	node *temp = malloc(sizeof(node));
	temp->info = val;
	if(*h == NULL) {
		temp->prev = temp->next = temp;
		*h = temp;  *t = temp;
	} else {
		(*h)->prev->next = temp;
		(temp)->prev = (*h)->prev;
		(*h)->prev = temp;
		temp->next = (*h);
		*t = temp;
	}
}

display(node *h)
{
	printf("List:\t%d ", h->info);
	h = h->next;
	while(h != head) {
		printf("%d ", h->info);	
		h = h->next;
	}
	printf("\n");
}



int main()
{
	system("clear");
	printf("---------CIRCULAR DOUBLY LINKED LIST---------\n\n\n\tEnter elements of the list:\n");
	int n; scanf("%d", &n);
	while(n != -1) {
		insert(&head, &tail, n);
		display(head);
		scanf("%d", &n);
	}
	
	printf("\n\n\n\tTail: %p\tHead previous: %p\n", (head->prev), tail);
	printf("\n\tHead: %p\tTail next: %p\n\n\n\n\n", head, tail->next);
	return 0;
}
