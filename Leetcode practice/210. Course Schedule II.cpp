#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;

vector<int> graph[maxn];
int vis[maxn];
stack<int> st;
bool findCycle(int u)
{
    if(vis[u]==1){
        return true;
    }
    vis[u] = 1;
    for(int v: graph[u]){
        if(vis[v]!=2)
            if(findCycle(v)){
                return true;
            }
    }
    vis[u] = 2;
    return false;
}

void dfs(int u)
{
    if(vis[u]) 
        return ;
    vis[u] = 1;
    for(int v: graph[u]){
        dfs(v);
    }
    st.push(u);
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        for(int i = 0;i<numCourses;i++){
            vis[i] = 0;
            graph[i].clear();
        }

        for(pair<int,int> &ii: prerequisites){
            graph[ii.second].push_back(ii.first);
        }
        vector<int> vec;
        for(int i = 0;i<numCourses;i++){
            if(vis[i]==0){
                if(findCycle(i))
                    return vec;
            }
        }
        memset(vis,0,sizeof(vis));
        while(st.size()) st.pop();
        for(int i = 0;i<numCourses;i++){
            if(vis[i]==0) dfs(i);
        }
        while(st.size()){
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};


int main()
{
    return 0;
}