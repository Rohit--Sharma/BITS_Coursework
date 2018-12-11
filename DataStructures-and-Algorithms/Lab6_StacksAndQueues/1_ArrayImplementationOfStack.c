#include<stdio.h>
#include<stdlib.h>

int pos = 0;							//Current position in stack.
int n;									//Size of the stack obtained at run-time.

void push(int *a, int val) {
	if(!isFull(a, n))
		*(a + pos++) = val;
	else
		printf("Stack is full.\n");
}
int pop(int *a) {
	if(!isEmpty(a))
		return *(a + --pos);
	else {
		printf("Stack is empty.\n");
		return -1;
	}
}
int size(int *a) {
	return pos;
}
int isEmpty(int *a) {
	if(size(a) == 0) return 1;
	else return 0;
}
int isFull(int *a, int sz) {
	if(size(a) == sz) return 1;
	else return 0;
}

int main() {
	int i, k; scanf("%d", &n);
	int *stk = malloc(sizeof(int)*n);	//Array implementation of stack.
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		push(stk, k);
	}
	//push(stk, 10);					//If uncommented this line, error message prompting "stack is full" will be displayed.
	for(i=0; i<n; i++) {
	//	printf("%d", *(stk+i));
		k = pop(stk);
		printf("%d ", k);
	}
	//pop(stk);							//If uncommented this line, error message prompting "stack is empty" will be displayed.
	printf("\n");
	return 0;
}


/*
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#define size 5
/* stack structure
struct stack  {
          int s[size];
          int top;
           }st;
//-------------------------------------
int stfull()
{
 if(st.top>=size-1)
    return 1;
 else
    return 0;
}
//-------------------------------------
void push(int item)
{
 st.top++;
 st.s[st.top] =item;
}
//-------------------------------------
int stempty()
{
 if(st.top==-1)
    return 1;
 else
    return 0;
}
//-------------------------------------
int pop()
 {
 int item;
 item=st.s[st.top];
 st.top--;
 return(item);
 }
//-------------------------------------
void display()
{
 int i;
 if(stempty())
    printf("\n Stack Is Empty!");
 else
  {
  for(i=st.top;i>=0;i--)
     printf("\n%d",st.s[i]);
  }
}
//-------------------------------------
void main(void)
{
int item,choice;
char ans;
st.top=-1;
system("clear");
printf("\n\t\t Implementation Of Stack");
do
{
 printf("\n Main Menu");
 printf("\n1.Push\n2.Pop\n3.Display\n4.exit");
 printf("\n Enter Your Choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
        printf("\n Enter The item to be pushed: ");
        scanf("%d",&item);
        if(stfull())
            printf("\n Stack is Full!");
        else
            push(item);
        break;
  case 2:
        if(stempty())
            printf("\n Empty stack!Underflow !!");
        else
          {
          item=pop();
          printf("\n The popped element is %d",item);
          }
        break;
  case 3:
        display();
        break;
  case 4:
        exit(0);
 }
 printf("\n Do You want To Continue? ");
 scanf("%c", &ans);
}while(ans == 'Y'||ans == 'y');
getchar();
}
*/
