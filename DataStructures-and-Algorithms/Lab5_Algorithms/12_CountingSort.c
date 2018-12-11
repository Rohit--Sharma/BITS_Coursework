#include<stdio.h>
#include<stdlib.h>
int *arr;
void clear_bit(long i)
{
    arr[i>>5] &= ~(1<<(i & 0x1f));
}

void set_bit(long i)
{
     arr[i>>5] |= (1 << (i & 0x1f)); /* bitwise SHIFT, OR, AND operators */
    // printf("%d\n",arr[i]);
}
int test_bit(long i)
{
    return arr[i>>5] & (1<<(i & 0x1f));
}


main()
{
    int n;
    scanf("%d",&n);
    long a[n],i;
    srand(time(NULL));
   // randomize();
    for(i=0;i<n;i++)
    {
        a[i]=rand()%n;
    printf("%ld\t",a[i]);
    }
    printf("\n\n\n\n\n");
    arr=malloc(sizeof(int)*10000000/32);


    for(i=0;i<10000000;i++)
    {
        clear_bit(i);
    }

    for(i=0;i<n;i++)
    {
        set_bit(a[i]);
    }
    long tmp;
    for(i=0;i<10000000;i++)
    {


        tmp=test_bit(i);
       // printf("%ld",tmp);
       if(tmp>0)
        printf("%ld\t",i);
    }


}
