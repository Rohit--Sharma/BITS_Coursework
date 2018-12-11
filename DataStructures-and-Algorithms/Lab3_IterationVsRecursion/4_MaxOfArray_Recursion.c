#include<stdio.h>
#include<stdlib.h>

int max(int *arr, int sz) {
	static int m = 0, ii = 0;
	if(ii<sz) {
		if(*(arr+ii) > m) 
			m = *(arr+ii); 
		ii++;
		max((arr), sz);
	}
	return m;
}

int main() {
	int n; scanf("%d", &n);
	int *a = malloc(sizeof(int)*n);

	int i=0;
	for(; i<n; i++) {
		scanf("%d", a+i);
	}

	printf("%d\n", max(a, n));

	return 0;
}
