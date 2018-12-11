#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	clock_t begin, end;
	double time_spent;
	begin = clock();

	int n, i; scanf("%d", &n);
	long long *a = malloc(sizeof(long long)*n);

	for(i=2; i<n; i++) 
		*(a+i) = 0;
	
	*(a) = 0; *(a+1) = 1;
	for(i=2; i<n; i++) {
		*(a+i) = *(a+i-1) + *(a+i-2);
	}

	printf("%lld\n", *(a+n-1));
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	return 0;
}
