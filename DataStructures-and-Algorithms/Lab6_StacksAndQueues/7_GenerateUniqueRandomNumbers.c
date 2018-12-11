#include<stdio.h>
main() {
    int n, r, k, temp;
	srand(time(NULL));
    scanf("%d%d", &n, &r);
    int x[r], i;
    for(i=0; i<r; i++)       
    	x[i] = i;
	for(i=0; i<n; i++) {
		k=rand()%(r-i) + i;
		x[i] = x[i] + x[k] - (x[k] = x[i]);
	}
	for(i=0; i<n; i++) 
		printf("%d ", x[i]);
	printf("\n");
}
