#include<stdio.h>
#include<stdlib.h>

quick(int *arr, int size) {
	if(size == 0) return;
	int pvt = *(arr);
	int *y= malloc(sizeof(int)*50), *z= malloc(sizeof(int)*50);
	int size_y=0, size_z=0;
	int i;
	for(i=1; i<size; i++) {
		if(*(arr+i)>pvt) { *(z+size_z)=*(arr+i); size_z++; }
		else if(*(arr+i)<=pvt) { *(y+size_y) = *(arr+i); size_y++; }
	}
	quick(y, size_y);
	printf("%d ", pvt);
	quick(z, size_z);
}

int main() {
	printf("Enter number of elements: ");
	int n; scanf("%d", &n);
	int *a = malloc(sizeof(int)*n);
	int i, j, k, l;
	printf("Enter %d integers: \n", n);
	for(i=0; i<n; i++) {
		scanf("%d", a+i);
	}
	quick(a, n);
	printf("\n");
	return 0;
}
