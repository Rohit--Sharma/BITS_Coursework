#include<stdio.h>
#include<stdlib.h>
#include<time.h>

quick(int *arr, int size) {
	if(size == 0) return;
	int pvt = *(arr);
	int *y= malloc(sizeof(int)*1000000), *z= malloc(sizeof(int)*1000000);
	int size_y=0, size_z=0;
	int i;
	for(i=1; i<size; i++) {
		if(*(arr+i)>pvt) { *(z+size_z)=*(arr+i); size_z++; }
		else if(*(arr+i)<=pvt) { *(y+size_y) = *(arr+i); size_y++; }
	}
	quick(y, size_y);
	//printf("%d ", pvt);
	quick(z, size_z);
}

int main() {
	int n = 1000; clock_t quick_begin, quick_end; double quick_time;
	int *a = malloc(sizeof(int)*n);
	int i, j, k, l;
	//printf("Enter %d integers: \n", n);
	for(i=0; i<n; i++) {
		*(a+i) = rand()%2000;
	}
	quick_begin = clock(); 
	quick(a, n);
	quick_end = clock();
	quick_time = (double)(quick_end - quick_begin) / CLOCKS_PER_SEC;
	printf("%f\n", quick_time);
	
	n = 10000;
	int *b = malloc(sizeof(int)*n);
	//printf("Enter %d integers: \n", n);
	for(i=0; i<n; i++) {
		*(a+i) = rand()%2000000;
	}
	quick_begin = clock(); 
	quick(a, n);
	quick_end = clock();
	quick_time = (double)(quick_end - quick_begin) / CLOCKS_PER_SEC;
	printf("%f\n", quick_time);
	return 0;
}
