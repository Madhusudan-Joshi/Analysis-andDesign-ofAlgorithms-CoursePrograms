#include<stdio.h> 
#include<conio.h>
void warshall(int a[10][10], int n)
{
  int i, j, k;
    for(k=0;k<n;k++)
         for(i=0;i<n;i++)
           if(a[i][k]==1)
             for(j=0;j<n;j++)
                 a[i][j] = a[i][j] || a[k][j];
}
int main()
{
   int n, i, j, a[10][10];
   printf("Enter number of vertices:"); scanf("%d",&n);
   printf("\nEnter adjacency matrix :\n"); 
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         scanf("%d",&a[i][j]);
    warshall(a,n);
    printf("\nThe transitive closure is :\n"); 
    for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
         printf("%d\t",a[i][j]); printf("\n");
    }
    return 0;
}