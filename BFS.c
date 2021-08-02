#include<stdio.h>
#include<stdlib.h>
void BFS(int a[10][10], int source, int *visited, int n){
    int q[10], u, front =0, rear = -1, i;
    q[++rear] = source;
    visited[source] = 1;
    printf("reachable vertices are : ");
    printf("%d ",source);
    while(front<=rear){
        u = q[front++];
        for(i=0;i<n;i++){
            if((a[u][i] == 1) && (visited[i] == 0)){
                q[++rear] = i;
                visited[i] = 1;
                printf("%d ",i);
            }
        }
    }
}
int main(){
    int n, a[10][10], visited[10],i,j;
    printf("Enter the size of the matrix: ");
    scanf("%d",&n);
    printf("Enter the adjecency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
    printf("BFS order of ");
    BFS(a,0,visited,n);
    for(i=0;i<n;i++){
        if(visited[i] == 0){
            printf("\nGraph is disconnected\n");
            return 0;
        }
    }
    printf("\nGraph is connected\n");
    return 0;
}