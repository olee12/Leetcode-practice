#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
const int maxn = 26;
queue<int> q;
vector<int> adj[maxn];
int rnk[maxn];
int dist[maxn];
const int CASE = 'A';
void init(int n) {
    while(q.size()) q.pop();
    for(int i = 0;i<maxn;i++){
        adj[i].clear();
        rnk[i] = 0;
        dist[i] = 0;
    }
}


int main() {
    int n,m;
    int u,v;
    char inp[5];

    while(scanf("%d",&n)!=EOF) {
        scanf("%d",&m);
        scanf("%s",inp);
        init(n);
        for(int i = 0;i<strlen(inp);i++) {
            int ch = inp[i] - CASE;
            rnk[ch] = 3;
            q.push(ch);
        }
        for(int i = 0;i<m;i++) {
            scanf("%s",inp);
            int u = inp[0] - CASE;
            int v = inp[1] - CASE;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int visited = 0;
        int mx_dist = 0;
        while(q.size()){
            int u = q.front();
            q.pop();
            visited++;
            for(int i = 0;i<adj[u].size();i++) {
                int v = adj[u][i];
                rnk[v]++;
                if(rnk[v]==3) {
                    dist[v] = dist[u] + 1;
                    mx_dist = max(dist[v],mx_dist);
                    q.push(v);
                }
            }
        }
        if(visited == n){
            printf("WAKE UP IN, %d, YEARS\n",mx_dist);
        } else {
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
        
    }
    return 0;
}