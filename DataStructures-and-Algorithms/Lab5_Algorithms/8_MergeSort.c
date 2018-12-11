#include<stdio.h>
#include<stdlib.h>

void divide(int *,int,int);
void merge(int *,int,int,int);
int n;
int main()
{
    int *a,i;
    scanf("%d",&n);
    a = malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    scanf("%d",a+i);

    divide(a,0,n-1);

    for(i=0;i<n;i++)
    printf("%d\t",a[i]);

    return 0;
}

void divide(int *a,int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        divide(a,low,mid);
        divide(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int *a,int low,int mid,int high)
{
    int l = low;
    int m=mid+1;
    int i=low;
    int temp[n];
    while(l<=mid && m<=high)
    {
        if(a[l]<=a[m])
        temp[i++] = a[l++];
        else
        temp[i++] = a[m++];
    }

    if(l>mid)
    {
        while(m<=high)
        temp[i++] = a[m++];
    }

    if(m>high)
    {
        while(l<=mid)
        temp[i++] = a[l++];
    }

    for(i=low;i<=high;i++)
    a[i] = temp[i];
}
