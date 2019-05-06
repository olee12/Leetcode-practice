#include <bits/stdc++.h>
using namespace std;

const int maxn = 106;
int graph[maxn][maxn];
int grid[maxn][maxn];
int front[maxn];
int lft[maxn];

int main() {
    int n,m,h;
    scanf("%d %d %d",&n,&m,&h);
    for(int i = 0;i<m;i++) scanf("%d",front+i);
    for(int i = 0;i<n;i++) scanf("%d",lft+i);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int j = 0;j<m;j++){
        for(int i = 0;i<n;i++){
            if(graph[i][j]>0) grid[i][j] = front[j];
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(graph[i][j] > 0){
                if(grid[i][j]>lft[i]) grid[i][j] = lft[i];
            }
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(j) printf(" ");
            printf("%d",grid[i][j]);
        }
        printf("\n");
    }
}