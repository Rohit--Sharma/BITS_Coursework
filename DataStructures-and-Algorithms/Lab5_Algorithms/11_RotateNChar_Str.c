#include<stdio.h>
#include<stdlib.h>
#include<string.h>

reverse(char *c, int strt, int end) {
    if(strt<end) {
		char temp;
		temp = *(c+strt);
		*(c+strt) = *(c+end);
		*(c+end) = temp;
		reverse(c, strt+1, end-1);
	}
}
int main() {
	char *ch = malloc(255);
	printf("Enter a string: ");
    scanf("%s", ch);
	printf("Enter how many characters to rotate: ");
    int i, n=strlen(ch);
    scanf("%d", &i);
    reverse(ch, 0, i-1);
    reverse(ch, i, n-1);
    reverse(ch, 0, n-1);
    printf("Rotated string: %s\n", ch);
	return 0;
}
