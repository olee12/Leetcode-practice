#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;

vector<int> graph[maxn];
int vis[maxn];
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

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
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
                    return false;
            }
        }
        return true;
    }
};


int main()
{
    return 0;
}