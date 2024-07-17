#include<stdio.h>

int s[20];
int j;
int res[20];

void dfs(int u, int n, int a[n][n]){
    s[u] = 1;
    for(int v = 0; v < n; v++){
        if(a[u][v] == 1 && s[v] == 0){
            dfs(v, n, a);
        }
    }
    res[j++] = u;
}

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
    for(int i = 0; i < n; i++){
        s[i] = 0;
    }
    j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 0){
            dfs(i, n, a);
        }
    }
    printf("Soln: \n");
    for(int i = n - 1; i >= 0; i--){
        printf("%d ", res[i]);
    }

    return 0;
}
