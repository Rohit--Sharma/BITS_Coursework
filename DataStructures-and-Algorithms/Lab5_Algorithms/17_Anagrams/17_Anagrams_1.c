#include<stdio.h>
#include<stdlib.h>
#include<string.h>

sort(char *s) {
	int n = strlen(s);
	int i, j; char t;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if(*(s+j) > *(s+j+1)) {
				t=*(s+j); *(s+j)=*(s+j+1); *(s+j+1)=t;
			}
		}
	}
}
int main() {
	FILE *fp, *f;
	fp = fopen("wordfile.txt", "r");
	f = fopen("sort.txt", "w");
	char *cpy, *ch;
	ch = malloc(50); cpy = malloc(50);
	while(fscanf(fp, "%s", ch) != EOF) {
		strcpy(cpy, ch);
		sort(cpy);
		fprintf(f, "%s\t%s\n", cpy, ch);
	}
	if(fp)
		fclose(fp);
	if(f)
		fclose(f);
	return 0;
}
