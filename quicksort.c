#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int milliSec){
    clock_t start_time = clock();
    while(clock() < start_time + milliSec);
}

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int a[], int low, int high) 
{
  int pivot = a[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (a[j] <= pivot) 
    {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return (i + 1);
}

void quickSort(int a[], int low, int high)
 {
    if (low < high)
   {
    delay(1);
    int pi = partition(a, low, high);
    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
  }
}

int main()
{   int a[10000];
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

    quickSort(a,0,n);
    end=clock();
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    time = (double)(end-start)/CLK_TCK;
	printf("\nTime Taken : %f\n",time);

}