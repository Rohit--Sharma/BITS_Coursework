#include<stdio.h>
#include<stdlib.h>

int part(int *a, int p, int r) {
	/*int x = *(a+p);
	int i = p-1;
	int j = r+1;
	while(1) {
		while(*(a+j)<=x)
			j--;
		while(*(a+i)>=x)
			i++;
		if(i<j) {
			int temp = *(a + i);
			*(a + i) = *(a + j);
			*(a + j) = temp;
		}
		else return j;
	}*/
	int piv = *(a+p);
	int low = p, high = r;
	while(low<high) {
		while(*(a+low)<=piv)
			low++;
		while(*(a+high)>=piv)
			high--;
		if(low<high) {
			int temp=*(a+low);
			*(a+low)=*(a+high);
			*(a+high)=temp;
		}
	}
	*(a+low)=*(a+high);
	*(a+high)=piv;
	return high;
}
int r_partition(int *a, int p, int r) {
	srand(time(NULL));
	int i = rand()%(r - p) + p;
	int temp = *(a + i);
	*(a + i) = *(a + p);
	*(a + p) = temp;
	return part(a, p, r);
}
int selecte(int *a, int p, int r, int i) {
	if(p == r) 
		return *(a+p);
	int q = part(a, p, r); //r_partition(a, p, r);
	int k = q - p + 1;
	printf("\n%d %d", i, k);
	if(i <= k) 
		return selecte(a, p, q, i);
	else 
		return selecte(a, q+1, r, i-k);
}
int main() {
	int k, i; scanf("%d", &k);
	int *a = malloc(sizeof(int) * 20);
	srand(time(NULL));
	for(i=0; i<20; i++) {
		a[i] = rand()%100;
		printf("%d ", a[i]);
	}
	printf("\n%d\n", selecte(a, 0, 19, k));
	return 0;
}
