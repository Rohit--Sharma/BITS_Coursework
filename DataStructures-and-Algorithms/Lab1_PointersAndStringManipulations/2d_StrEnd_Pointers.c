#include<stdio.h>

int strend(char *s, char *t) {
    int i = 0, j=0, k=0, l=0;
    while(*(t + j++) != '\0'); j--; //size of t=j
    while(*(s + k++) != '\0'); k--; //size of s=k
    i = k-j;
    while(*(s + i) != '\0') {
        if(*(s+i) == *(t+l)) {
            i++; l++;
            continue;
        }
        i++;
    }
    if(*(s+i) == '\0' && *(t+l) == '\0') return 1;
    else return 0;
}
int main() {
    printf("%d", strend("hello madame", "ame"));
    return 0;
}
