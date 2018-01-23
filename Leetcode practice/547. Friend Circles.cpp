#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector< bool > vis(M.size(),0);
        // vector<int> olee(5,2);
        // cout<<olee.size()<<endl;
        int cnt = 0;
        for(int i = 0;i<M.size();i++) {
            if(vis[i]==0) {
                dfs(M,vis,i);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(vector< vector<int> > &M,vector<bool> &vis,int u){
        vis[u] = 1;
        for(int i = 0;i<vis.size();i++){
            if(M[u][i]==0) continue;
            if(vis[i]) continue;
            dfs(M,vis,i);
        }
    }
};

int main()
{

}

