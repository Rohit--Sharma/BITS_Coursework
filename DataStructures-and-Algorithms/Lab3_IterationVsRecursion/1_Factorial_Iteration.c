#include<stdio.h>

int main() {
	int n, fact=1, i; scanf("%d", &n);
	for(i=1; i<=n; i++)
		fact *= i;
	printf("%d\n", fact);
	return 0;
}
