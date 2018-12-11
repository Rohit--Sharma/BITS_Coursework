//	Infix to postfix

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int pos = 0;							//Current position in stack.
int n;									//Size of the stack obtained at run-time.
char infix[50];
void push(char *a, char val) {
	if(!isFull(a, n))
		*(a + pos++) = val;
	else
		printf("Stack is full.\n");
}
char pop(char *a) {
	if(!isEmpty(a))
		return *(a + --pos);
	else {
		printf("Stack is empty.\n");
		return 0;
	}
}
int size(char *a) {
	return pos;
}
int isEmpty(char *a) {
	if(size(a) == 0) return 1;
	else return 0;
}
int isFull(char *a, int sz) {
	if(size(a) == sz) return 1;
	else return 0;
}
char top(char *a) {
	return *(a+pos-1);
}

char * inf_to_pst(char *infix) {
	char stk[25], *post = malloc(n);
	int i=0, j=0;
	//printf("   %d   ", n);
	while(i<n) {
		switch(*(infix+i)) {
			case '(': {
				push(stk, '(');
				i++;
				break;
			}
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
				*(post+j++) = *(infix+i);
				i++;
				break;
			}
			case '+': case '-': {
				if(top(stk) == '+' || top(stk) == '-') {
					*(post+j++) = pop(stk);
					push(stk, *(infix+i));
				}
				else if(top(stk) == '/' || top(stk) == '*') {
					//push(stk, *(infix+i++));
					*(post+j++) = pop(stk);
					push(stk, *(infix+i));
				}
				else if(isEmpty(stk)) {
					push(stk, *(infix+i));
				}
				i++;
				break;
			}
			case '/': case '*': {
				if(top(stk) == '+' || top(stk) == '-') {
					push(stk, *(infix+i));
				}
				else if(top(stk) == '/' || top(stk) == '*') {
					*(post+j++) = pop(stk);
					push(stk, *(infix+i));
				}
				i++;
				break;
			}
			
		}
		
	}
	while(!isEmpty(stk)) {
		*(post+j++) = pop(stk);
	}
	return post;
	//*(post+j++) = pop(stk);
}
int main() {
	char *postfix;
	scanf("%s", infix);
	n = strlen(infix);
	postfix = inf_to_pst(infix);
	printf("%s", postfix);
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int top = -1;
void push(char n,char a[])
{
	top++;
	a[top] = n;
}
char pop(char a[])
{
	char item;
 item = a[top];
 top--;
 return(item);
}
 int priority(char elem) { 
     switch (elem) {
     case 'f':
      return 0;
     case '(':
      return 1;
     case '+':
     case '-':
      return 2;
     case '*':
     case '/':
      return 3;
     }
 }
 main()
 {
 	int i = 0, k = 0,len;
 char s[100], s1[100], ch, ele;
 char *arr;
 
 printf("enter the Infix Expression\n");
 gets(s);
 len = strlen(s);
 	arr = (char *)malloc(sizeof(char)*len);
 push('f',arr);
 while ((ch = s[i++]) != '\0') {
      if (ch == '(')
            push(ch,arr);
      else if (isalnum(ch))
            s1[k++] = ch;
      else if (ch == ')') {
            while (arr[top] != '(')
                s1[k++] = pop(arr);
            ele = pop(arr); 
      } else { 
           while (priority(arr[top]) >= priority(ch))
                 s1[k++] = pop(arr);
           push(ch,arr);
      }
 }
 while (arr[top] != 'f') 
    s1[k++] = pop(arr);
 s1[k] = '\0'; 
 printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n", s, s1);
}
