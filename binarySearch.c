#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int milliSec){
    clock_t start_time = clock();
    while(clock() < start_time + milliSec);
}

void sort(int *a, int n){
	int pivot, temp, i, j;

	for(i=1;i<n;i++){
		pivot = a[i];
		for(j=i-1;j>=0;j--){
			if(a[j] > pivot){
				temp = a[j];
				a[j] = pivot;
				a[j+1] = temp;
			}
		}
	}
}

int BSearch(int *a, int n, int key, int low, int high){
	int mid;
	mid = (low+high)/2;

	delay(500);

	if(low > high){
		return 0;
	}

	if(key == a[mid]){
		return (mid+1);
	}
	else if(key > a[mid]){
		BSearch(a,n,key,mid+1,high);
	}
	else{
		BSearch(a,n,key,low,mid-1);
	}

}


int main()
{

	int a[100000], n, i, key, pos;
	clock_t start, end;
	double time;
    printf("Enter the number of elements you want to enter?\n");
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {  a[i] = i;
	   printf(" %d ",a[i]);
       
    }
    printf("\nEnter the key to be searched : ");
	scanf("%d",&key);
		
	sort(a,n);
	start = clock();
	pos = BSearch(a,n,key,0,n-1);
	end = clock();
			

    if(pos!=0)printf("Key Found\n");
	else printf("Key Not Found\n");

	time = (end-start)/CLK_TCK;
	printf("\nTime Taken : %f\n",time);

	return 0;
}