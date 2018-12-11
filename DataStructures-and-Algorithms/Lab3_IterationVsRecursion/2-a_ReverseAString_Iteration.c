#include<stdio.h>
#include<string.h>
#include<stdlib.h>

rev(char *s) {
	int l = strlen(s);
	while(l) {
		printf("%c", *(s+l-1));
		l--;
	}
}

int main() {
	char *str = malloc(255);
	scanf("%s", str);
	rev(str);
	printf("\n");
	return 0;
}
