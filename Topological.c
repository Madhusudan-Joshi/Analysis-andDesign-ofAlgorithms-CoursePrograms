#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, count =0, a[10][10], inDeg[10], flag[10], i,j,k;
    printf("Enter the number of vertex: ");
    scanf("%d",&n);
    printf("Enter the adjecency matrix :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        flag[i] = 0; inDeg[i] = 0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            inDeg[i] += a[j][i];
        }
    }
    printf("Topologial Order is: ");
    while(count < n){
        for(k=0;k<n;k++){
            if(inDeg[k] == 0 && flag[k] == 0){
                printf("%d ",k);
                flag[k] = 1;
                count++;
                for(i=0;i<n;i++){
                    if(a[k][i] == 1){
                        inDeg[i]--;
                    }
                }
            }
        }
    } return 0;
}