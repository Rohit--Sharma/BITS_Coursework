#include<stdio.h>

int strlen(char *str) {
    printf("%s\n", str);
    int i=0;
    while(*(str+i) != '\0') {
        i++;
    }
    return i;
}
int main() {
    char *st = malloc(256);
    printf("--------------------PROGRAM THAT FINDS LENGTH OF A STRING--------------------\n\n\n\n\n");
    printf("Enter a string: ");
    scanf("%255s", st);
    printf("\nThe length of \"%s\" is %d.\n\n", st, strlen(st));
    free(st);
    return 0;
}
