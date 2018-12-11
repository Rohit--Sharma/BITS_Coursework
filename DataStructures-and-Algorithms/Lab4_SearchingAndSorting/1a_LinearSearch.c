#include<stdio.h>

int main() {
	int a[] = {12, 14, 4, 9, 17, 3}, i, n, f=0;
	printf("Enter a number: "); scanf("%d", &n);
	for(i=0; i<sizeof(a)/sizeof(int); i++) {
		if(a[i] == n) { f=1; break; }
	}
	if(f == 1) printf("It is found!\n");
	else printf("It is not found!\n");
	return 0;
}
