#include<stdio.h>
int *zero_array(int *a, int length) {
    int i = 0;
    for(; i<length; i++) {
        *(a + i) = 0;
    }
}
int main() {
    int n, i=0; scanf("%d", &n);
    int *p; int ar[n];
    p = zero_array(ar, n);
    for(; i<n; i++)
        printf("\n%d", ar[i]);
    return 0;
}

