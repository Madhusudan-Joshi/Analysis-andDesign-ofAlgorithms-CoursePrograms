#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int milliSec){
    clock_t start_time = clock();
    while(clock() < start_time + milliSec);
}

int select(int *a, int n, int key){
	int i;
	for(i=0;i<n;i++){
		delay(1);
		if(key == a[i]){
			return (i+1);
		}
	}
	return 0;
}

int main()
{
    int a[50000], n, i, key, pos;
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
    start = clock();
	pos = select(a,n,key);
	if(pos!=0)printf("Key Found\n");
	else printf("Key Not Found\n");
    end = clock();
	time = (double)(end-start)/CLK_TCK;
	printf("\nTime Taken : %f\n",time);
    return 0;
}

	