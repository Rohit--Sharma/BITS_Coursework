#include<stdio.h>
#include<stdlib.h>

int main() {
	printf("Enter number of elements: ");
	int n; scanf("%d", &n);
	int *a = malloc(sizeof(int)*n);
	int i, j, k;
	printf("Enter %d integers: \n", n);
	for(i=0; i<n; i++) {
		scanf("%d", a+i);
	}
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if(*(a+j)>*(a+j+1)) {
				k = *(a+j+1); *(a+j+1) = *(a+j); *(a+j) = k;
			}
		}
	}
	printf("Sorted numbers: \n");
	for(i=0; i<n; i++) {
		printf("%d ", *(a+i));
	}
	printf("\n");
	return 0;
}
