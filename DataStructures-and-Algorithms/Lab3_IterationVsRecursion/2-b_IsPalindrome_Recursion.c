#include<stdio.h>
#include<stdlib.h>
#include<string.h>

palind(char *s) {
	if(strlen(s) == 1) {
		printf("Palindrome\n");
	}
	else if(strlen(s) == 2 && *(s) == *(s+1)) {
		printf("Palindrome\n");
	}
	else if(*(s) == *(s+strlen(s)-1)) {
		s = s+1; *(s+strlen(s)-1) = '\0';
		palind(s);
	}
	else 
		printf("Not a palindrome.\n");
}

int main() {
	char *str = malloc(sizeof(char)*255);
	scanf("%s", str);
	palind(str);
	return 0;
}
