#include<stdio.h>
#include<stdlib.h>

int power( int n, int exp) {
	static int ans = 1;
	if(exp>0) {
		ans *= n;
		exp--;
		power(n, exp);
	}
	return ans;
}

int main() {
	int x, y; scanf("%d %d", &x, &y);
	printf("%d\n", power(x, y));
	return 0;
}
