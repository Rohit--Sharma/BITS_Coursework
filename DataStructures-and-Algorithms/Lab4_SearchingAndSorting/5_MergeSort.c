#include<stdio.h>
#include<stdlib.h>

partition(int *arr, int strt, int end) {
	int med;
	if(strt<end) {
		med = (strt+end)/2;
		partition(arr, strt, med);
		partition(arr, med+1, end);
		merge(arr, strt, med, end);
	}
} 

merge(int *arr, int strt, int med, int end) {
	int lo1=strt, lo2=med+1, count, ans[50], i=strt; 
	while((lo1<=med)&&(lo2<=end)) {
		if(*(arr+lo1)>*(arr+lo2)) { ans[i] = *(arr+lo2); lo2++; }
		else { ans[i] = *(arr+lo1); lo1++; }
		i++;
	}
	if(lo1>med) {
		for(count=lo2; count<=end; count++) {
			ans[i] = *(arr+count); i++;
		}
	}
	else {
		for(count=lo1; count<=med; count++) {
			ans[i] = *(arr+count); i++;
		}
	}
	for(i=strt; i<=end; i++) {
		arr[i] = ans[i];
	}
}

int main() {
	printf("Enter number of elements: ");
	int n; scanf("%d", &n);
	srand(time(NULL));
	int *a = malloc(sizeof(int)*n);
	int i, j, k, l;
	printf("Enter %d integers: \n", n);
	for(i=0; i<n; i++) {
		//scanf("%d", a+i);
		*(a+i) = rand()%100;
	}
	i=0; k=n-1;
	partition(a, i, k);
	printf("Sorted numbers: \n");
	for(i=0; i<n; i++) {
		printf("%d ", *(a+i));
	}
	printf("\n");
	return 0;
}
