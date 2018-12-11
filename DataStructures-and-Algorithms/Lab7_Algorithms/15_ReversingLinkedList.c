#include<stdio.h> 
 //#include<conio.h>
 #include<stdlib.h>
 struct node
 {
        int num;
        struct node* next;
 };
 void list_add(struct node **n, int val)  {
 struct node *temp = NULL;
 temp = malloc(sizeof(struct node) );
 temp->num = val;
 temp->next = *n;
 *n = temp;
}
void list_reverse(struct node **n)  {
 struct node *a = NULL;
 struct node *b = NULL;
 struct node *c = NULL;
 a = *n, b = NULL;
 
 while(a != NULL) {
  c = b, b = a, a = a->next;
  b->next = c;
 }
 
 *n = b;
}
 
void list_display(struct node *n) {
 while(n != NULL)
  printf(" %d", n->num), n = n->next;
 
 printf("\n");
}
 main()
 {
 	struct node *new = NULL;
 	int n,m,k;
 	do
 	{
 		printf("1.enter into list\n2.display original list\n3.display reverse of the list\n");
 		scanf("%d",&n);
 		switch(n)
 		{
 			case 1:
 			       printf("enter the integer\n");
 			       scanf("%d",&m);
 			       list_add(&new, m);
 			       break;
            case 2:printf("the original list is : \n");
                   list_display(new);
                  break;
            case 3:
                   list_reverse(&new);
                   printf(" the reversed list is : \n");
                   list_display(new);
                   break;
 		}printf("press 1 to continue\n");
 		scanf("%d",&k);
 	}while(k==1);
 }
