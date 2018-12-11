#include<stdio.h>

void strcpy(char *src, char *des) {
    int i = 0;
    while(*(src+i) != '\0'){
        *(des + i) = *(src + i);
        i++;
    }
    *(des + i) = '\0';
    //printf("%s\n", des);
}
int main() {
    char *str = malloc(256);
    //str = NULL;
    printf("-------------------PROGRAM THAT COPIES A STRING TO A LOCATION-------------------\n\n\n\n\n");
    printf("Enter a string: ");
    scanf("%255s", str);
    char *dest = malloc(256);
    //printf("%d\n", &dest);
   // printf("%d\n", &str);
   // printf("%s\n", dest);
    strcpy(str, dest);
    //dest = str;
   // printf("%d\n", &dest);
   // printf("%d\n", &str);
    printf("Copied string: %s\n", dest);
    return 0;
}
