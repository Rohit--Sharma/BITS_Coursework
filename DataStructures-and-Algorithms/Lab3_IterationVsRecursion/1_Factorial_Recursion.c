#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long int fact(int x) {
	if(x==1) return 1;
	else 
		return x*fact(x-1);
}

int main() {
	int t, n;
	scanf("%d", &t);
	while(t) {
		scanf("%d", &n);
		printf("%ld\n", fact(n));
		t--;
	}
	return 0;
}
