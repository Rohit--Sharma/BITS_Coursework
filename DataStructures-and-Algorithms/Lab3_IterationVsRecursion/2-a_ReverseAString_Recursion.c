#include<stdio.h>
#include<stdlib.h>

rev(char *s) {
	if(*s!='\0'){
		rev((s+1));
		printf("%c", *(s));
	} 
}

int main() {
	char *st = malloc(sizeof(char)*255);
	scanf("%s", st);
	rev(st);
	printf("\n");
	return 0;
}
