#include<stdio.h>
static int f = 0;
search(int ar[], int min, int max, int med, int n) {
	
	if(n<ar[min] || n > ar[max]) {
		f=0; return;
	}
	else if(ar[med] == n || ar[min] == n || ar[max] == n) {
		printf("Found.\n"); f = 1; return;
	}
	else if(ar[med]>n) {
		search(ar, min, med-1, (min+max)/2.0, n);
	}
	else if(ar[med]<n)search(ar, med+1, max, (min+max)/2.0, n);
	
}
int main() {
	int a[] = {3, 4, 9, 12, 14, 17}, n, i, j, k;
	printf("Enter a number: "); scanf("%d", &n);
	i = 0; j = sizeof(a)/sizeof(int)-1; k = (int)(i+j)/2.0;
	search(a, i, j, k, n);
	if(f==0) printf("Not found.\n");
	return 0;
}
