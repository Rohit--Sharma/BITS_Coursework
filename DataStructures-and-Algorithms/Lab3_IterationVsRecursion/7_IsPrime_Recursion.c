#include <stdio.h>
#include <math.h>

void isprime(int n) {
	static int d = 2;
	if(d <= sqrt(n)) {
		if(n%d == 0) {
			printf("Not a prime\n"); 
			return;
		}
		else {
			d++;
			isprime(n);
		}
	}
	else printf("Prime\n");
}

int main ()
{
	int x; scanf("%d", &x);
	isprime(x);
	return(0);
}
