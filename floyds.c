#include<stdio.h> 
#include<conio.h>
void floyd(int cm[10][10], int n)
{
   int i, j, k;
   for(k=0;k<n;k++)
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
             if((cm[i][k]+cm[k][j])<cm[i][j])
                 cm[i][j] = cm[i][k]+cm[k][j];
}
int main()
{
 int n, i, j, cm[10][10]; 
 printf("Enter number of vertices:"); scanf("%d",&n);
 printf("\nEnter adjacency matrix (for infinity, put 9999):\n"); for(i=0;i<n;i++)
 for(j=0;j<n;j++)
      scanf("%d",&cm[i][j]);
floyd(cm,n);
printf("\nThe all pair shortest path is :\n"); 
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
        printf("%d\t",cm[i][j]);
        printf("\n");
 }
return 0;
}