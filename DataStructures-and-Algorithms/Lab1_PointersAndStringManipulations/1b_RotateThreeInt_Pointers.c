#include<stdio.h>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    rotate(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}
rotate(int *x, int *y, int *z) {
    int temp;
    temp = *x; *x = *y; *y = *z; *z = temp;
}
