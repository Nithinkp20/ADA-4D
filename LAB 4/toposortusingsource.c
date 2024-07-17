#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter adjacency matrix: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int indegree[n];
    for(int j = 0; j < n; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i][j];
        }
        indegree[j] = sum;
    }
    int s[n];
    int top = -1;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            top++;
            s[top] = i;
        }
    }
    int soln[n];
    int si = 0;
    while(top != -1){
        int u = s[top];
        top--;
        soln[si++] = u;
        for(int i = 0; i < n; i++){
            if(a[u][i] == 1){
                indegree[i]--;
                if(indegree[i] == 0){
                    top++;
                    s[top] = i;
                }
            }
        }
    }
    printf("Soln: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", soln[i]);
    }
    return 0;
}
