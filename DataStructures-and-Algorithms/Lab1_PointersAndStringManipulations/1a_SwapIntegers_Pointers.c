#include<stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("\n%d %d", a, b);
	return 0;
}
swap(int *x, int *y) {
	//(*x)^=((*y)^=((*x)^=(*y)));
	int tep;
	tep = *x; *x = *y; *y = tep;
}

//https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA
