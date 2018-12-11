#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}node;

node *list1 = NULL, *list2 = NULL, *tail1 = NULL, *tail2 = NULL;

insert_to_tail(node **l, int v)
{
	node *temp = malloc(sizeof(node));
	temp->val = v;
	temp->next = *l;
	*l = temp;
	if(*l == NULL) {
		insert_to_tail(l, v);
		*l = (*l)->next;
		return;
	}
}

display(node *l)
{
	l = l->next;
	if(l == NULL)
		return;
	display(l);
	printf("%d->", l->val);
}

int isPresent(node *l, int v) 
{
	while(l != NULL) {
		if(l->val == v)
			return 1;
		l = l->next;
	}
	return 0;
}

node *get_union(node *l1, node *l2)
{
	node *res = NULL;
	while(l1 != NULL) {
		insert_to_tail(&res, l1->val);
		l1 = l1->next;
	}
	while(l2 != NULL) {
		if(!isPresent(res, l2->val))
			insert_to_tail(&res, l2->val);
		l2 = l2->next;
	}
	return res;
}

node *get_Intersect(node *l1, node *l2)
{
	node *res = NULL;
	while(l1 != NULL) {
		if(isPresent(l2, l1->val))
			insert_to_tail(&res, l1->val);
		l1 = l1->next;
	}
	if(res == NULL) {
		printf("No intersection.\n");
		return NULL;
	}
	return res;
}

int main()
{
	int i; char c;
	printf("Enter list-1: ");
	scanf("%d%c", &i, &c);
	insert_to_tail(&list1, i);
	while(c!='\n') {
		scanf("%d%c", &i, &c);
		insert_to_tail(&list1, i);
	}
	printf("Enter list-2: ");
	scanf("%d%c", &i, &c);
	insert_to_tail(&list2, i);
	while(c!='\n') {
		scanf("%d%c", &i, &c);
		insert_to_tail(&list2, i);
	}

	printf("List-1: ");	
	
	display(list1); printf("%d\n", list1->val);
	
	printf("List-2: ");
	display(list2); printf("%d\n", list2->val);
	
	
	printf("Union: ");
	node *uni = get_union(list1, list2);
	display(uni); printf("%d\n", uni->val);

	printf("Intersection: ");
	
	if(get_Intersect(list1, list2) != NULL) {
		node *inter = get_Intersect(list1, list2);
		display(inter); printf("%d\n", inter->val);
	}

	return 0;
}
