#include<stdio.h>
#include<string.h>
#include<stdlib.h>

push(char *stack, char c, int *top) {
	*(stack+(++(*top))) = c;
}
char pop(char *stack, int *top) {
	if(*top>-1)
		return *(stack+(*top)--);
}
rev(char s[]) {
	int len = strlen(s), i, top=-1, j;
	char *stk = malloc(len);
	for(i=0; i<len; i++) {
		push(stk, s[i], &top);
	}
	for(i=0; i<len; i++) {
		s[i] = pop(stk, &top);
	}
	i=0;
	while(i<len) {
		j=0;
		while(s[i] != ' ' && i<len) {
			push(stk, s[i], &top);
			i++; j++;
		}
		i=i-j;
		while(j--) {
			s[i] = pop(stk, &top);
			i++;
		} 
		while(s[i] == ' ') {
			i++;
		}
	}
}
int main() {
	char str[256];
	scanf("%[^\n]", str);
	rev(str);
	printf("%s\n", str);
	return 0;
}
