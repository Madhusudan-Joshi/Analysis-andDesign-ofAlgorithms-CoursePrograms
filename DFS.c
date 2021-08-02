#include<stdio.h>
#include<stdlib.h>
void DFS(int n, int a[10][10], int u, int visited[]){
    int v;
    visited[u] = 1;
    printf("%d ",u);
    for(v=0;v<n;v++){
        if((a[u][v] == 1) && (visited[v]==0)){
            DFS(n,a,v,visited);
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
    printf("DFS order is ");
    DFS(n,a,0,visited);
    printf("\n");
    for(i=0;i<n;i++){
        if(visited[i] == 0){
            printf("Graph is disconnected\n");
            return 0;
        }
    }
    printf("Graph is connected\n");
    return 0;
}