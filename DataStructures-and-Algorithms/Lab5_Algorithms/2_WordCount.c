#include<stdio.h>

int main() {
	FILE *fp; 
	fp = fopen("wordfile.txt", "r");
	int i=0; char c;
	fscanf(fp, "%c", &c);
	while(!feof(fp)) {
		//if(c == ' ' || c == '\n') i++;
		i++;
		fscanf(fp, "%c", &c);
	}
	printf("%d\n", i);
	fclose(fp);
	return 0;
}
