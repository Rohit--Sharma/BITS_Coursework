#include<stdio.h>
#include<string.h>
int main()
{
FILE *fp,*f;
fp=fopen("sort.txt","r");
int lines=0;
char str[50];
while(fgets(str,50,fp)!=NULL)
lines++;
fclose(fp);

fp=fopen("sort.txt","r");
char s[50];
int x = lines*2;
char words[x][10];
int i=0,j=0;

	while(fscanf(fp,"%s",s)!=EOF)
	{
	strcpy(words[i],s);
	i++;
	}
fclose(fp);	
	f=fopen("anagrams.txt","w");
	
	fprintf(f,"%s",words[1]);
	
	for(i=0;i<2*lines-3;i=i+2)
	{
		if(strcmp(words[i],words[i+2])==0)
		fprintf(f,"\t%s",words[i+3]);
		else
		fprintf(f,"\n%s",words[i+3]);
	}
	fclose(f);
	
	

return 0;
}
