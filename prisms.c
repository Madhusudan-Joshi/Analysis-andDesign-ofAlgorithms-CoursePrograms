#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,n,i,j,count=1;
    int cost[15][15];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the adjacent matrix\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    int min,mincost,u,v,visited[15]={0};
    visited[0]=1;
    printf("The edges of minimum spanning graph are :-");
    while(count <n)
    { min=999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==0)
                        continue;
                    else
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0)
        {   
            count++;
            printf("\nEdge(%d,%d) = %d",a,b,min);
            mincost+=min;   
             visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nThe cost of the minimum spanning tree is %d\n",mincost);
    return 0;
}