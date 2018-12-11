#include<stdio.h>
#include<stdlib.h>

to_binary(int n) {
	int *a = malloc(sizeof(int)*50);
	int sz = 0;
	while(n) {
		*(a+sz) = n%2; 
		n /= 2;
		sz++;
	}
	while(sz) {
		printf("%d ", *(a+sz-1));
		sz--;
	}
}

int main() {
	int n; scanf("%d", &n);
	to_binary(n);
	return 0;
}
