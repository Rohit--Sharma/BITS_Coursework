#include<stdio.h>

void towers(int n, char fromrod, char torod, char intermediaterod) {
	if(n == 1) {
		printf("Disk 1 moving from rod %c to rod %c using %c as intermediate rod\n", fromrod, torod, intermediaterod);
		return;
	}
	towers(n-1, fromrod, intermediaterod, torod);
	printf("Disc %d moving from rod %c to rod %c using %c as intermdiate rod\n", n, fromrod, torod, intermediaterod);
	towers(n-1, intermediaterod, torod, fromrod);
}

int main() {
	int x; scanf("%d", &x); 
	towers(x, 'A', 'B', 'C');
	return 0;
}
