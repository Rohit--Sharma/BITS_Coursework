#include<stdio.h>
#include<stdlib.h>
int top1 = -1;
int top2 = -1;
int count = 0;

void push1( int n , int a[])
{
	a[++top1] = n;
}
void push2( int n , int a[])
{
	a[++top2] = n;
}
void enqueue(int a[],int n)
{
	int i;
	if(isfull1(n))
		printf("Queue is full\n");
	else
	{
	    printf("Enter the element:\n");
	    scanf("%d",&i);
	    push1(i,a);
	    count++;
	}
}
void dequeue(int a1[] ,int a2[],int n )
{
    int i;
    //if(isempty2(n))
	//printf("its empty\n");
	//else
	
    for (i = 0;i <= count;i++)
    {
    	 printf("%d\n",pop1(a1));
         push2(pop1(a1),a2);       
    }
    printf("Dequed element is %d\n",pop2(a2));
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2(a2),a1);
    }
	
}
void display(int a[])
{
    int i;
 
    for (i = 0;i <= top1;i++)
    {
        printf(" %d ", a[i]);
    }
}
int isfull1(int size)
{
	if(top1 >=size-1)
    return 1;
 else
    return 0;
}
int pop1(int a[])
{
	int item;
 item = a[top1];
 top1--;
 return(item);
 }	
int isempty2( int n)
{
	if(top2 == -1)
    return 1;
 else
    return 0;
}
int pop2(int a[])
{
	int item;
 item = a[top2];
 top2--;
 return(item);
 }  	
main()
{
	int n,m,k;
	int *arr1;
	int *arr2;
	printf("enter the size\n");
	scanf("%d",&n);
	arr1 = (int*)malloc(sizeof(int)*n);
	arr2 = (int*)malloc(sizeof(int)*n);
	do
	{
		printf("1.enqueue\n2.dequeue\n3.display\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:
			enqueue(arr1,n);
			break;
			case 2:
			dequeue(arr1,arr2,n);
			break;
			case 3:
			display(arr1);
			break;
		}
		printf("press 1 to continue\n");
		scanf("%d",&k);
	}while(k);
}  
