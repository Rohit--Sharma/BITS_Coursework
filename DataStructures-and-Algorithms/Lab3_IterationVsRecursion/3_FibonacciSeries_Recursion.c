#include<stdio.h>
#include<time.h>

long long fib(int x) {
	long long f;
	if(x==1){
		f=0;
	}
	else if(x==2) {
		f=1;
	}
	else {
		f = fib(x-1) + fib(x-2);
	}
	return f;
}
int main() {
	clock_t begin, end;
	double time_spent;
	begin = clock();
	int a; scanf("%d", &a);
	long long ans = fib(a);
	printf("%lld\n", ans);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	return 0;
}
