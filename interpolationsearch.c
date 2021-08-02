#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10000
void delay(int milliSec){
    clock_t start_time = clock();
    while(clock() < start_time + milliSec);
}
int interpolationSearch(int arr[], int n, int x)
{
    int start = 0, end = (n - 1);
    while (start <= end && x >= arr[start] && x <= arr[end])
    { delay(1);
        if (start == end)
        {
            if (arr[start] == x) return start;
            return -1;
        }
        
        int pos = start + (((double)(end - start) /
            (arr[end] - arr[start])) * (x - arr[start]));
 
        if (arr[pos] == x)
            return pos;
      
        if (arr[pos] < x)
            start = pos + 1;
            
        else
            end = pos - 1;
    }
    return -1;
}
void sort(int a[], int n)
 {
   int i, j, temp;
   for(i=0;i<n-1;i++)
   { 
     for(j=i+1;j<n;j++)
      {
       if(a[i]>a[j])
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
        }
      }
   }
 }
 int main()
{
	int arr[200000],brr[200000],i,r,n,x;
	clock_t start, end;
    double time;
	printf("Enter the array size:");
    scanf("%d",&n);
    start=clock();
    printf("\nElements are:\n");
    for(int j=0;j<n;j++)
   arr[j]=-1;
   for(int i=0;i<n;i++)
   {
      r = rand() % n + 1;
      for(int j=0;j<n;j++)
      {
        if(r == arr[j]) 
        { 
          r = rand() % n + 1;
          j=-1;
        }
    }
        arr[i]=r;
    }
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    sort(arr,n);
    printf("\nAfter Sorting array :\n");
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t", arr[i]);
    }
    printf ("\nEnter the Element to be Searched:\n");
	scanf("%d",&x); 
	int index = interpolationSearch(arr,n,x);
    end=clock();
	if (index == -1){
		printf("Element not found.");
	}
	else
	{   
	    printf("Element found at index %d", index);
		time=(double)(end-start)/CLOCKS_PER_SEC;
        printf("\n Time taken = %f", time);
	}
	return 0;
}


