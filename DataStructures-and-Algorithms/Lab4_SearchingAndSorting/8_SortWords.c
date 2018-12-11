#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int n, i, j; scanf("%d", &n);
	char *str[n], *temp=malloc(50); 
	for(i=0; i<n; i++) {
		str[i] = malloc(50);
	}
	for(i=0; i<n; i++) {
		scanf("%s", str[i]);
	}
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if(strcmp(str[j], str[j+1]) > 0) {
				strcpy(temp, str[j]); 
				strcpy(str[j], str[j+1]); 
				strcpy(str[j+1], temp);
			}
		}
	}
	for(i=0; i<n; i++) {
		printf("%s ", str[i]);
	}
	printf("\n");
	return 0;
}
