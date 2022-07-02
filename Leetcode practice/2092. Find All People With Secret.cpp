#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    unordered_map<int,int> visited;
    vector<vector<pair<int,int> > > graph;
    unordered_map<int,bool> seen;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        graph = vector<vector<pair<int,int>>> (n, vector<pair<int,int>>());
        seen.clear();
        visited.clear();
        for(auto &vec : meetings) {
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        
        /*
        for(int i = 0;i<n;i++) {
            printf("%d: ", i);
            for(auto &it : graph[i]) {
                printf("[%d %d] ", it.first, it.second);
            }
            printf("\n");
        }
        */
        
      return  bfs(0, firstPerson);
        
        vector<int> ret;
        for(auto &it : visited) {
            if (it.second)
            ret.push_back(it.first);
        }
        return ret;
    }
    void dfs(int u, int par,  int t) {
        if (visited.count(u)) {
            if(visited[u] <= t) return;
        }
        visited[u] = t;
        
        vector<pair<int,int>>::iterator pos = upper_bound(graph[u].begin(), graph[u].end(), t, [](int b, pair<int,int> const &a) -> bool {
           return a.second >= b; 
        });
        
        for(vector<pair<int,int>>::iterator it = pos;it!=graph[u].end();it++) {
            pair<int,int> v = *it;
            //cout << u << ' '<< v.first << ' '<< v.second << endl;
            if (v.first == par) continue;
            dfs(v.first, u, v.second);
        }
    }

    vector<int> bfs(int u, int firstPerson) {
        queue<pair<int,int>> q;
        q.push({u,0});
        q.push({firstPerson,0});
        

        while(q.size()) {
            
            unordered_map<int,int> min_cost;
            min_cost.clear();
            while(q.size()) {
                pair<int,int> cur = q.front();q.pop();
                int u = cur.first, t = cur.second;
                visited[u] = t;

                for(auto &v : graph[u]) {
                    if(visited.count(v.first)) {
                        if(visited[v.first]<=t)
                        continue;
                    }
                    if(v.second >= t) {
                        //printf("--u: %d, v:%d, t:%d\n", u, v.first, v.second);
                        if(min_cost.count(v.first)) {
                            min_cost[v.first] = min(min_cost[v.first], v.second);
                        }else {
                            min_cost[v.first] = v.second;
                        }
                    }
                }
           }
            vector<pair<int,int>> nxt;
            for_each(min_cost.begin(), min_cost.end(), [&](auto &it) {
                nxt.push_back({it.first, it.second});
            });
            sort(nxt.begin(), nxt.end(), [](auto &a, auto &b)->bool{ return a.second<b.second;});
            for(auto &it:nxt) q.push(it);
  
        }
        vector<int> ret;
        for(auto &it : visited) {
            ret.push_back(it.first);
        }
        return ret;
    }
    

    vector<int> bfs2(int u, int firstPerson) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> q;
        q.push({0, u});
        q.push({0, firstPerson});
        
        while(q.size()) {
            auto x = q.top();q.pop();
            int u = x.second;
            int t = x.first;
            if (visited[u]) continue;
            visited[u] = true;
            for(auto &v:graph[u]) {
                if(visited[v.first] == false && v.second >= t) {
                    //cout << "u: "<<u<<" v: "<<v.first << " v.second: "<< v.second << " t: "<< t<<endl;
                    q.push({v.second, v.first});
                }
            }
        }
        vector<int> ret;
        for(auto &it : visited) {
            if(it.second)
            ret.push_back(it.first);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
