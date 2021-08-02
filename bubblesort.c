#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int milliSec){
    clock_t start_time = clock();
    while(clock() < start_time + milliSec);
}

void swap(int *a, int *b) 
{ int t = *a;
  *a = *b;
  *b = t;
}

void bubblesort(int arr[], int n)
{  int i, j;
   for (i = 0; i < n-1; i++)     
   {   delay(1);
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
   }
}
int main()
{   int a[100000];
    clock_t start, end;
	double time;
    int i,n;
    printf("Enter size");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();

    bubblesort(a,n);
    end=clock();
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    time = (double)(end-start)/CLK_TCK;
	printf("\nTime Taken : %f\n",time);

}