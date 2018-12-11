#include<stdio.h>
#include<stdlib.h>

char *reverse(char *original) {
    int k=0, i=0;
    while(*(original + k++) != '\0'); k--;
    char *rev=malloc(k);
    for(; i<k; i++) {
        *(rev+i) = *(original+(k-i-1));
    }
    *(rev+k) = '\0';
    return rev;
}
int main() {
    printf("%s", reverse("Rohit"));
    return 0;
}
