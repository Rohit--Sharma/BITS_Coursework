#include<stdio.h>

int n=20;
int median(int *ar) {
	int i, min1=200, min2=200, medi=200;
	for(i=0; i<5; i++) {
		if(*(ar+i)<min1) min1=*(ar+i);
	}
	for(i=0; i<5; i++) {
		if(*(ar+i)<min2 && *(ar+i)>min1) min2=*(ar+i);
	}
	for(i=0; i<5; i++) {
		if(*(ar+i)<medi && *(ar+i)>min2) medi=*(ar+i);
	}
	//printf("%d ", medi);
	return medi;
}
int mom(int *arr, int x) {
	int k, i=0, medians[n/5], ans, xless[20], xgreat[20] ;
	for(k=0; k<n; k+=5) {
		medians[i++] = median(arr+k);
	}
	int med_of_med = mom(medians, n/10); i=0; int j=0;
	for(k=0; k<n; k++) {
		if(arr[k] <= med_of_med) xless[i++] = arr[k];
		else xgreat[j++] = arr[k];
	}
	if(i == x-1) return arr[x-1];
	else if(i>x) return mom(xless, x);
	else return mom(xgreat, k-i-1);
	
}
int main() {
	int k, i; scanf("%d", &k);
	int a[20];
	srand(time(NULL));
	for(i=0; i<20; i++) {
		a[i] = rand()%100;
		printf("%d ", a[i]);
	}
	printf("\n");
	mom(a, k);
	return 0;
}
