#include<stdio.h>
#include<stdlib.h>

int main() {
	printf("Enter number of elements: ");
	int n; scanf("%d", &n);

	int *a = malloc(sizeof(int)*n), *b = malloc(sizeof(int)*n);
	int i, j, k, l;

	printf("Enter %d integers: \n", n);
	for(i=0; i<n; i++) {
		scanf("%d", a+i);
	}
	for(i=0; i<n; i++) {
		*(b+i) = *(a+i);
	}

	for(i=1; i<n; i++) {
		for(j=0; j<i; j++) {
			if(*(b+j) > *(a+i)) {
				for(k=i; k>j; k--) {
					*(b+k) = *(b+k-1);
				}
				*(b+j) = *(a+i);
				break;
			}
		}
	}

	printf("Sorted numbers: \n");
	for(i=0; i<n; i++) {
		printf("%d ", *(b+i));
	}
	printf("\n");

	return 0;
}
