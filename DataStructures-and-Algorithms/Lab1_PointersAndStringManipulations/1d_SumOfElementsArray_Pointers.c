#include<stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    printf("%d", sum(arr, n));
    return 0;
}
int sum(int *p, int lgt) {
    int i, sum = 0;
    for(i = 0; i<lgt ;i++) {
        scanf("%d", (p + i));
        sum += *(p + i);
    }
    return sum;
}
