#include <stdio.h>
int main() {
    int n, i, ans;
    printf("--------------------PROGRAM THAT FINDS A NUMBER IN AN ARRAY--------------------\n\n\n\n\n");
    printf("Enter a size for the array: "); scanf("%d", &n);
    int a[n];
    int *p = a;
    printf("\nEnter the elements of the array: ");
    for(i = 0; i<n ;i++) {
        scanf("%d", (p + i));
    }
    printf("\nEnter the number to be found: ");
    int x; scanf("%d", &x);
    ans = find(a, n, x);
    if(ans != -1)
        printf("\n%d is found at location %d in the array.\n\n\n",x ,ans);
    else printf("\nThe number %d could not be found in the array.\n\n\n", x);
    return 0;
}
int find(int *p, int lgt, int xt) {
    int i;
    for(i = 0; i<lgt ;i++) {
        if((*(p+i)) == xt) return i+1;
        //else return -1;
       // printf(" %d ", *(p+i));
    }
    return -1;
}
