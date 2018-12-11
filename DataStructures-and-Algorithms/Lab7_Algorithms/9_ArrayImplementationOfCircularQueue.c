/*#include<stdio.h>
#include<stdlib.h>

int n;

int isFull(int *top, int *rear) {
	if(((*top)%n) < ((*rear)%n)) return 1;
	else return 0;
}
enqueue(int *a, int val, int *top, int *rear) {
	if(!isFull(top, rear)) {
		*(a + ((*top)%n)) = val;
		(*top)++;
	}
	else
		printf("Queue is full!!!\n");
}
int dequeue(int *a, int *top, int *rear) {
	
}
int main() {
	int k, i, top=0, rear=0; scanf("%d", &n);
	int *queue = malloc(sizeof(int) * n);
	
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		enqueue(queue, k, &top, &rear);
	}
	enqueue(queue, 1, &top, &rear); enqueue(queue, 1, &top, &rear);
	return 0;
}*/

//Program for Circular Queue implementation through Array
#include <stdio.h>
#include<stdlib.h>
//#include<conio.h>
#define MAXSIZE 5
int cq[MAXSIZE]={0};
int front,rear;
void main()
{
 void add(int);
 void del();
 void display();
 int ch,i,num;
 front = -1;
 rear = -1;
 system("clear");
 printf("\nProgram for Circular Queue demonstration through array");
 while(1)
 {
  printf("\n\nMAIN MENU\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.EXIT");
  printf("\n\nENTER YOUR CHOICE : ");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:
   printf("\n\nENTER THE QUEUE ELEMENT : ");
   scanf("%d",&num);
   add(num);
   break;
  case 2:
   del();
   break;
  case 3:
      display();
       break;
  case 4:
       exit(0);
  default: printf("\n\nInvalid Choice . ");
  }

 }
}


void add(int item)
{
 if(front == (rear+1)%MAXSIZE)
 {
 	printf("\n\nCIRCULAR QUEUE IS OVERFLOW");
 }
 else
 {
   if(front==-1)
     front=rear=0;
   else
     rear = (rear+1)%MAXSIZE;
   cq[rear]=item;
   printf("\n\nRear = %d  &  Front = %d",rear,front);
 }
}


void del()
{
int a;
if(front == -1)
 {
 	printf("\n\nCIRCULAR QUEUE IS UNDERFLOW");
 }
 else
 {
  	a=cq[front];
    cq[front]=0;
  	if(front==rear)
   		front=rear=-1;
  	else
    	front = (front+1)%MAXSIZE;
  	printf("\n\nDELETED ELEMENT FROM QUEUE IS : %d ",a);
  	printf("\n\nRear = %d  &  Front = %d",rear,front);

 }
}

void display()
{
 int i;
 for(i=0;i<MAXSIZE;i++)
   printf("%d\t",cq[i]);
}
