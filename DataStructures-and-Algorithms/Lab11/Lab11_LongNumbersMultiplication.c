#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int ndgt(int x)
{
	int c=0;
	while(x > 0) {
		x /= 10;
		c++;
	}
	return c;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

long mul(int a, int b)
{
	int n = max(ndgt(a), ndgt(b));
	if(n == 1) {
		//printf("a: %d, n: %d\n", a, n);
		return a*b;
	} 
	if(n == 0) {
		return 0;
	}
	if(n%2 == 0) {
		//printf("%d ", n);
		int ah = a/(int)(pow((float)10, n/2)), al = a%(int)(pow((float)10, n/2));
		int bh = b/(int)(pow((float)10, n/2)), bl = b%(int)(pow((float)10, n/2));
		//printf("%d %d %d %d\n",ah, al, bh, bl);
		long x1, x2, x3, x4;
		x1 = mul(ah, bh); x2 = mul(ah, bl); x3 = mul(al, bh); x4 = mul(al, bl); 
		//printf("%ld %ld %ld %ld ", x1, x2, x3, x4);
		return (x1 * (long)(pow((float)10, n)) + (x2 + x3) * (long)(pow((float)10, n/2)) + x4);
	} else {
		int ah = a/(int)(pow((float)10, (n/2+1))), al = a%(int)(pow((float)10, (n/2+1)));
		int bh = b/(int)(pow((float)10, (n/2+1))), bl = b%(int)(pow((float)10, (n/2+1)));
		//printf("%d %d %d %d\n",ah, al, bh, bl);
		long x1, x2, x3, x4;
		x1 = mul(ah, bh); x2 = mul(ah, bl); x3 = mul(al, bh); x4 = mul(al, bl); 
		//printf("%ld %ld %ld %ld ", x1, x2, x3, x4);
		return (x1 * (long)(pow((float)10, n+1)) + (x2 + x3) * (long)(pow((float)10, (n+1)/2)) + x4);
	}
}

int main()
{
	int a, b;
	long c;
	printf("\tEnter 1st number: ");
	scanf("%d", &a);
	printf("\tEnter 2nd number: ");
	scanf("%d", &b);
	c = mul(a, b);
	printf("\n\tProduct: %ld\n", c);
	return 0;
}

