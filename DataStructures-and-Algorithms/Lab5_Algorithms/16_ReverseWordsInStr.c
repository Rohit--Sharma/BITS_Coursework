#include<stdio.h>
#include<string.h>

main()
{
    int i=0,j=0;
    char str[100],t[100][10],tmp[10];
    scanf("%[^\n]", str);

    char *token=strtok(str," ");
    while(token)
    {
      strcpy(t[i++],token);
      token=strtok(NULL," ");
    }

    //printf("%d",i);
     for(j=0;j<i;j++)
    printf("%s\n",t[j]);

    for(j=0;j<i/2;j++)
    {
        strcpy(tmp,t[j]);
        strcpy(t[j],t[i-1-j]);
        strcpy(t[i-1-j],tmp);
    }

    for(j=0;j<i;j++)
    printf("%s ",t[j]);


}
