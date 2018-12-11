#include<stdio.h>

main()
{
    int n;
    scanf("%d",&n);
    int a[n],i=0;
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);

    int b[100],c[n];

    for(i=0;i<100;i++)
   		b[i]=0;

    for(i=0;i<n;i++)
    	b[a[i]]+=1;

    for(i=1;i<100;i++)
    	b[i]+=b[i-1];

    for(i=n-1;i>=0;i--)
    {
        c[b[a[i]]-1]=a[i];
        b[a[i]]--;
    }

    for(i=0;i<n;i++)
    	printf("%d\t",c[i]);
}
