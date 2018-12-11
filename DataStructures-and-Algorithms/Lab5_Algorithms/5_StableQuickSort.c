#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick(long *a,long low,long high)
{
    if(low<high)
    {
        double pivot=a[low];
        long l=low+1;
        long r=high; long temp;

            while(l<=r)
            {
                while(a[l]<=pivot)
                l++;

                while(a[r]>pivot)
                r--;

                if(l<r) { temp = a[r]; a[r] = a[l]; a[l] = temp; }
                //a[r] = a[l] + a[r] - (a[l]=a[r]);
            }
        //a[low] = a[r] + a[low] - (a[r]=a[low]);
        temp = a[r]; a[r] = a[low]; a[low] = temp;
        quick(a,low,r-1);
        quick(a,r+1,high);
    }
}

int main()
{
    clock_t start,end;
    srand(time(NULL));
    long i, n;
    long *a;
    scanf("%ld",&n);
    a=malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        a[i] = rand() % (n+100);
    }
    start=clock();
    quick(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",(int)a[i]); 
    end=clock();
    printf("\nTime Taken: %f\n",((double)end - (double)start) / CLOCKS_PER_SEC);
    return 0;
}


