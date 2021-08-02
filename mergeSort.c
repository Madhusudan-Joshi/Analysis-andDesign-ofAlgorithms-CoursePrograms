#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int milliSec){
    clock_t start_time = clock();
    while(clock() < start_time + milliSec);
}

int a[100000];

void merge(int a[], int lb, int m, int ub)
{
    int i, j, k;
    int n1 = m - lb + 1;
    int n2 = ub - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = a[lb + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = lb; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int lb,int ub)
{
   int m;
   delay(1);
   if(lb<ub)
   { m=(lb+ub)/2;
    mergesort(a,lb,m);
    mergesort(a,m+1,ub);
    merge(a,lb,m,ub);
   }
}

int main()
{
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
    mergesort(a,0,n);
    end=clock();
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    time = (double)(end-start)/CLK_TCK;
	printf("\nTime Taken : %f\n",time);
    return 0;
}