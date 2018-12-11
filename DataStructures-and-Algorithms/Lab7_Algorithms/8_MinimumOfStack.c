

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10

struct Stack
{
    int top;
    int *arr;
};

typedef struct Stack stack;

bool isEmpty(stack *temp)
{
    return temp->top==-1;
}

bool isFull(stack *temp)
{
    return temp->top==MAX-1;
}

stack* createStack()
{
    stack * temp = (stack *) malloc(sizeof(stack));
    temp->top=-1;
    temp->arr = malloc (sizeof(int)*MAX);
    return temp;
}

void push(stack *temp, int x)
{
if(isFull(temp))
   return;
  ++(temp->top);
   temp->arr[temp->top]=x;
}

int pop (stack *temp)
{
    if(isEmpty(temp))
        return;
    return temp->arr[temp->top--];
}

struct specialStack
{
    stack min;
    stack *org;
};

typedef struct specialStack specialStack;

specialStack* createSpecialStack()
{
    specialStack *temp = (specialStack *) malloc(sizeof (specialStack));
    temp->min   = * ((stack *) createStack());
    temp->org = createStack();
    return temp;
}

void pushS(specialStack *temp, int x)
{
    if(isEmpty(temp->org)==true)
    {
        push(temp->org,x);
        push(&(temp->min),x);
    }
    else
    {
        push(temp->org,x);
        int y = getMinS(temp);

        if(x<=y)
         push(&(temp->min),x);
    }
}

int getMinS(specialStack *temp)
{
     int y = pop(&(temp->min));
     push(&(temp->min),y);
     return y;
}

int popS(specialStack *temp)
{
    int x = pop(temp->org);
    int y = getMinS(temp);

    if(x==y)
      pop(&(temp->min));

    return x;
}

void display(stack *temp)
{
    int i = 0;
    printf("\n Contents: ");
    while(i<=temp->top)
       printf("%d->",temp->arr[i++]);
}

int main(void)
{
specialStack *var = createSpecialStack();

display (var->org);

pushS(var,5);
pushS(var,25);
pushS(var,0);
pushS(var,3);

display (var->org);

printf("\n  Min = %d", getMinS(var));

popS(var);
popS(var);

printf("\n  Min after pop twice = %d\n", getMinS(var));

return 0;
}

