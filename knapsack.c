#include<stdio.h> 
#include<conio.h>

int knapsack(int i, int cap, int n, int w[10],int v[10])
{
    int x, y;
    if (i==n)
    return ((cap<w[n])?0:v[n]);
    if(cap<w[ i ])
    return knapsack(i+1, cap, n, w, v);
    x=knapsack(i+1, cap, n, w, v);
    y=knapsack(i+1, cap-w[i], n, w, v) + v[ i ];
    return ((x>=y)?x:y);
}
void main()
{
    int n, i, w[10],v[10],cap, maxprofit;
    printf("Enter number of items:\n"); 
    scanf("%d",&n);
    printf("\nEnter respective weights:\n"); 
    for(i=0;i<n;i++)
    scanf("%d",&w[i]);
    printf("\nEnter respective profits/values:\n"); 
    for(i=0;i<n;i++)
    scanf("%d",&v[i]);
    printf("\nEnter capacity:"); scanf("%d",&cap);
    maxprofit=knapsack(0,cap,n,w,v); 
    printf("\nMaximum profit is: %d",maxprofit);
}
