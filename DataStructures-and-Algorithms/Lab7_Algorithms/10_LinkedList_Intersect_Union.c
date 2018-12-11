#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

push(struct node ** list, int val) {
	struct node * temp = malloc(sizeof(struct node));
	temp->data = val;
	temp->next = *list;
	*list = temp;
}

int isPresent(struct node *list, int val) {
	while(list != NULL) {
		if(list->data == val)
			return 1;
		list = list->next;
	}
	return 0;
}

struct node* getIntersection(struct node *l1, struct node* l2) {
	struct node *res = NULL;
	struct node *t1 = l1;

	while(t1 != NULL) {
		if(isPresent(l2, t1->data)) 
			push(&res, t1->data);
		t1 = t1->next;
	}

	return res;
}

struct node* getUnion(struct node *l1, struct node *l2) {
	struct node *res = NULL;
	struct node *t1 = l1, *t2 = l2;

	while(t1 != NULL) {
		push(&res, t1->data);
		t1 = t1->next;
	}
	
	while(t2 != NULL) {
		if(!isPresent(res, t2->data))
			push(&res, t2->data);
		t2 = t2->next;
	}
	
	return res;
}

disp(struct node *list) {
	while(list != NULL) {
		printf(" %d ", list->data);
		list = list->next;
	}
	printf("\n");
}



int main() {
	struct node* list1 = NULL;
	struct node* list2 = NULL;
	struct node* inter = NULL;
	struct node* uni = NULL;
	system("clear");
	printf("-------------C Program to find union and intersection of two lists-------------\n\n\n");
	printf ("\n\n\t First list is (Enter -1 to stop) : ");
	int i;
	scanf("%d", &i);
	while(i != -1) {
		push(&list1, i);
		scanf("%d", &i);
	}
	printf ("\n\n\t Second list is (Enter -1 to stop) : ");
	scanf("%d", &i);
	while(i != -1) {
		push(&list2, i);
		scanf("%d", &i);
	}
	
	inter = getIntersection(list1, list2);
	uni = getUnion(list1, list2);
	
	printf ("\n\n\t Intersection is : ");
	disp(inter);
	printf ("\n\n\t Union is : ");
	disp(uni);
	printf("\n\n\n\n\n");

	return 0;
}















/* geeks for geeks
#include<stdio.h>
#include<stdlib.h>
 
//* Link list node 
struct node
{
    int data;
    struct node* next;
};
 
//* A utility function to insert a node at the begining of a linked list
void push (struct node** head_ref, int new_data);
 
//* A utilty function to chec if given data is present in a list 
bool isPresent (struct node *head, int data);
 
//* Function to get union of two linked lists head1 and head2 
struct node *getUnion (struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1, *t2 = head2;
 
    // Insert all elements of list1 to the result list
    while (t1 != NULL)
    {
        push(&result, t1->data);
        t1 = t1->next;
    }
 
    // Insert those elements of list2 which are not present in result list
    while (t2 != NULL)
    {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
 
    return result;
}
 
//* Function to get intersection of two linked lists head1 and head2 
struct node *getIntersection (struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1;
 
    // Traverse list1 and search each element of it in list2. If the element
    // is present in list 2, then insert the element to result
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
 
    return result;
}
 
//* A utility function to insert a node at the begining of a linked list
void push (struct node** head_ref, int new_data)
{
    //* allocate node /
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    //* put in the data /
    new_node->data = new_data;
 
    //* link the old list off the new node /
    new_node->next = (*head_ref);
 
    //* move the head to point to the new node 
    (*head_ref) = new_node;
}
 
//* A utility function to print a linked list
void printList (struct node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
}
 
//* A utilty function that returns true if data is present in linked list
//else return false 
bool isPresent (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
 
//* Drier program to test above function
int main()
{
    //* Start with the empty list 
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* intersecn = NULL;
    struct node* unin = NULL;
 
    //*create a linked lits 10->15->5->20 
    push (&head1, 20);
    push (&head1, 4);
    push (&head1, 15);
    push (&head1, 10);
 
    //*create a linked lits 8->4->2->10 
    push (&head2, 10);
    push (&head2, 2);
    push (&head2, 4);
    push (&head2, 8);
 
    intersecn = getIntersection (head1, head2);
    unin = getUnion (head1, head2);
 
    printf ("\n First list is \n");
    printList (head1);
 
    printf ("\n Second list is \n");
    printList (head2);
 
    printf ("\n Intersection list is \n");
    printList (intersecn);
 
    printf ("\n Union list is \n");
    printList (unin);
 
    return 0;
}
*/
