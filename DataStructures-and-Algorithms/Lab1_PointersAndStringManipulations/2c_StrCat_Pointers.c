#include<stdio.h>
#include<stdlib.h>

char *strcate(char *s, char *t) {
    char *ans;
    int i=0; int j=0;
    while(*(s+i) != '\0') {
        *(ans + i) = *(s + i);
        i++;
    }
    while(*(t + j) != '\0') {
        *(ans + i + j) = *(t + j);
        j++;
    }
    *(ans + i + j) = '\0';
    return ans;
}
int main() {
    char *a = malloc(256);
    char *b = malloc(256);
    scanf("%255s", a); scanf("%255s", b);
    printf("%s", a);
    char *ans = strcate(a, b);
    //printf("%s", ans);
    free(a); free(b);
    return 0;
}

