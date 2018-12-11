#include<stdio.h>

int main() {
	int a[] = {3, 4, 9, 12, 14, 17}, i, n, f=0, j, k;

	printf("Enter a number: "); scanf("%d", &n);

	i = 0; j = sizeof(a) / sizeof(int) - 1; k = (int)(i + j) / 2.0;

	if(n<a[i] || n > a[j]) {
		printf("It is not found!\n");
		return 0;
	}

	while(i<j) {
		if(a[k] == n || a[i] == n || a[j] == n) {
			f=1; break;
		}
		else if(a[k]>n) {
			j = k-1; k = (i+j)/2.0;
		}
		else {
			i = k+1; k = (i+j)/2.0;
		}
	}

	if(f == 1) 
		printf("It is found!\n");
	else 
		printf("It is not found!\n");

	return 0;
}
	
