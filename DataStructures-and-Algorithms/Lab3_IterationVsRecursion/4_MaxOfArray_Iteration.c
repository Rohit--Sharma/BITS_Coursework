#include<stdio.h>
#include<stdlib.h>

int main() {
	int n; scanf("%d", &n);
	int *a = malloc(sizeof(int)*n);

	int i=0;
	for(; i<n; i++) {
		scanf("%d", a+i);
	}

	int max = 0;
	for(i=0 ; i<n; i++) {
		if(*(a+i) > max) 
			max = *(a+i);
	}
	printf("Maximum = %d\n", max);
	
	return 0;
}
