#include<stdio.h>
#include<stdlib.h>

int gcd(int n1, int n2) {
	if(n2>0) {
		gcd(n2, n1%n2);
	}
	else 
		return n1;
}

int main() {
	int x, y; scanf("%d %d", &x, &y);
	
	if(x>y)
		printf("%d\n", gcd(x, y));
	else
		printf("%d\n", gcd(y, x));

	return 0;
}
