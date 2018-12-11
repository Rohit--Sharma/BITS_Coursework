#include<stdio.h>
#include<stdlib.h>

radix(int *arr, int sz) {
	int bucket[10][5] = {0}, buck[10], i, l, k, div=1, j;
	
	int max=0;
	for(i=0; i<sz; i++) {
		if(*(arr+i) > max) max = *(arr+i);
	}
	int ndgt = 0;
	while(max) {
		ndgt++;
		max /= 10;
	}
	//printf("%d", ndgt);

	int pass;
	for(pass=0; pass<ndgt; pass++) {
		for(i=0; i<10; i++) {
			buck[i] = 0;
		}
		for(i=0 ; i<sz  ;i++) {
			l = ((arr[i]/div)%10);
			bucket[l][buck[l]++] = arr[i];
	   	}
		i=0;
	   	for(k=0 ; k<10 ; k++) {
			for(j=0 ; j<buck[k] ; j++) {
		 		arr[i++] = bucket[k][j];
			}
	   	}   
	   	div*=10;  
	}
}

int main() {
	int n, i; scanf("%d", &n);
	int *a = malloc(sizeof(int)*n);
	for(i=0; i<n; i++) {
		scanf("%d", (a+i));
	}
	radix(a, n);
	for(i=0; i<n; i++) {
		printf("%d  ", *(a+i));
	}
	return 0;
}
