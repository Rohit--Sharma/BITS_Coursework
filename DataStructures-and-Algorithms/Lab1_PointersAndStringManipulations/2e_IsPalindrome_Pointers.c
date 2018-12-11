#include<stdio.h>

void checkPalindrome(char *s) {
    int k=0, i=0, cou=0;
    while(*(s + k++) != '\0'); k--; //size of s=k
    //printf("%d", k);
    int l = k/2, j = k-1;
    for(;i<=(l-1);i++) {
        if(*(s+i) == *(s+j)) {
            j--;
            cou++;
        }
    }
    if(cou == l) printf("palindrome\n");
    else printf("no\n");
}
int main() {
    checkPalindrome("palindromeemordnilap");
    checkPalindrome("wataw");
    checkPalindrome("palindrom");
    return 0;
}
