#include<stdio.h>
#include<conio.h>

int main() {
    char ss[256];//char *ss=malloc(255);
    char ls[512];//char *ls=malloc(511);
    /*scanf("%s", ss);*/ gets(ss); gets(ls);
    int ans = 0, k=0, i=0, j=0;
    while(*(ss + k++) != '\0'); k--; //size of ss = k
    while(*(ls + i) != '\0') {
        j=0;
        while(*(ss + j) != '\0') {
            if(*(ls+i) == '\0') break;
            if(*(ls+i) == *(ss+j)) {
                j++; i++;
            }
            else {
                i++;
            }
        }
        if(j == k) ans++;
    }
    printf("%d", ans);
    return 0;
}
