#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void delay(int milliSec){
    clock_t start_time = clock();
    while(clock() < start_time + milliSec);
}
void selectionsort(int a[],int n)
{
    int i,j,min,t;
    for(i=0;i<n-1;i++)
    {   delay(1);
        min=i;
        for(j=i+1;j<n;j++)
        {
          if(a[j]<a[min])
          min=j;
        }
        if(min!=i)
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
}
int main()
{   clock_t start, end;
	double time;
    int i,n,a[100000];
    printf("Enter size");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    selectionsort(a,n+1);
    end=clock();
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    time = (double)(end-start)/CLK_TCK;
	printf("\nTime Taken : %f\n",time);

}