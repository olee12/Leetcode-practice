#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
vector<int> graph[maxn];
int dist[maxn];
int par[maxn];
void dfs(int u)
{
    for(int v:graph[u]){
        if(dist[v])
            continue;
        dist[v] = dist[u] + 1;
        par[v] = u;
        dfs(v);
    }
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;     
        if(n==0) return ans;   
        if(n==1){
            ans.push_back(n-1);
            return ans;
        }
        for(int i = 0;i<n;i++){
            graph[i].clear();
        }            

        for(pair<int,int> &ii:edges){
            graph[ii.first].push_back(ii.second);
            graph[ii.second].push_back(ii.first);
        }
        
        memset(dist,0,sizeof(int)*n);
        memset(par,-1,sizeof(int)*n);
        dist[0] = 1;
        
        dfs(0);
        int v = 0;
        for(int i = 1;i<n;i++){
            if(dist[i] > dist[v]){
                v = i;
            }
        }
        memset(dist,0,sizeof(int)*n);
        memset(par,-1,sizeof(int)*n);
        
        dist[v] = 1;
        dfs(v);
        int u = 0;
        for(int i = 1;i<n;i++){
            if(dist[i] > dist[u]){
                u = i;
            }
        }

        vector<int> path;
        path.push_back(u);
        while(par[u]!=-1){
            path.push_back(par[u]);
            u = par[u];
        }
        
        ans.push_back(path[path.size()/2]);
        if(path.size()%2==0)
            ans.push_back(path[path.size()/2 - 1]);
        return ans;

        
    }
};

int main()
{
    return 0;
}