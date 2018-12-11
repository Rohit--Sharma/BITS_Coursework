#include<stdio.h>

static int top = -1;

void push(int n, int a[])
{
	top++;
	a[top] = n;
}
int pop(int a[])
{
	int item;
	item = a[top];
	top--;
	topi(&top);
	return(item);
}
int isfull(int size)
{
	if (top >= size - 1)
		return 1;
	else
		return 0;
}
int isempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void display(int a[])
{
	int i;
	if (isempty())
		printf("n Stack Is Empty!");
	else
	{
		for (i = top; i >= 0; i--)
			printf("%d\n", a[i]);
	}
}
int  topi(int *tops)
{
	int k;
	k = *tops;
	return k;
}
void sort(int array[], int startpoint, int top)
{
	int i, k;
	int index1;
	if (startpoint == top - 1)
	{
		for (k = 0; k < top; k++)
			printf("%d\n", array[k]);
	}

	else {
		index1 = startpoint;

		//find smallest in rest of array
		for (i = startpoint; i < top; i++) if (array[i] < array[index1]) index1 = i;

		//put smallest in first spot
		swap(array, startpoint, index1);


		sort(array, startpoint + 1, top);
	}

}
void swap(int array[], int index1, int index2) {
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

main()
{
	int n, i, k, l, item;
	int *arr;
	int m;
	int *to;
	int ans;
	printf("enter the size of the stack\n");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	do
	{
		printf("1.push\n2.pop\n3.display\n4.sort\n");
		scanf("%d", &ans);
		switch (ans)
		{
		case 1:
			printf("enter the element to be pushed\n");
			scanf("%d", &k);
			if (isfull(n))
				printf("stack is full\n");
			else
				push(k, arr);
			break;
		case 2:
			if (isempty() == 1)
				printf("stack is empty\n");
			else
			{
				item = pop(arr);
				printf("popped item is %d\n", item);
			}
			break;
		case 3:
			display(arr);
			break;
		case 4:
			l = topi(to);
			sort(arr, 0, top + 1);
			break;
		}
		printf("press 1 to continue\n");
		scanf("%d", &m);
	} while (m);
}
