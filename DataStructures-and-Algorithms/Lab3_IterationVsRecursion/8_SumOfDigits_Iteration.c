#include<stdio.h>

int calculate_sum(int n) {
	int sum=0;
	while(n) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", calculate_sum(n));
	return 0;
}
