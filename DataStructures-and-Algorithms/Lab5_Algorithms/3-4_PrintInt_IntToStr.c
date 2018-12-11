#include<stdio.h>
#include<stdlib.h>

char s[50] = " "; int i=0;
print_int(int n) {
	if(n<0) {
		s[i++]='-';
		n *= (-1);
	}
	if(n>0) {
		print_int(n/10);
		s[i++]=n%10+'0';
	}
}

int main() {
	int i; scanf("%d", &i);
	if(i==0) {
		printf("0");
		return 0;
	}
	print_int(i);
	printf("%s", s);
	return 0;
}
