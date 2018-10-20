
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;


class node {
    public:
    int u,cost,steps;
    node(){}
    node(int _u,int _cost,int _steps): u(_u),cost(_cost), steps(_steps) {}

    bool operator < (const node &p) const {
        return cost > p.cost;
    }
};
class Solution
{
  public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int K)
    {
        return dijkstra(n,flights,src,dst,K);
    }

  private:
    int MAXN;
    vector<vector<int> > dist;

    int dijkstra(int n,vector<vector<int> >& flights, int src, int dst, int K) {
        if(n==1) return 0;
        int big = n*100000;
        dist = vector<vector<int> >(n + 5, vector<int>(n + 5, big ));
        //cout<<"row = "<<dist.size()<<" col: "<< dist[0].size()<<" val: "<<dist[0][0]<<endl;
        vector<pair<int,int> > adj[n];
        for(auto vec : flights){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            //printf("edge - %d %d %d\n",u,v,w);
            adj[u].push_back(make_pair(v,w));
        }
        priority_queue<node> q;
        q.push(node(src,0,0));
        dist[src][0] = 0;
        
        while(q.size()){
            int u = q.top().u;
            int cost = q.top().cost;
            int steps = q.top().steps;
            q.pop();
            if(steps == K+1) continue;
            //printf("U:  %d %d %d\n",u,cost,steps);
            for(int i = 0;i<adj[u].size();i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                int next_step = steps + 1;
                
                if(next_step <= K+1 && dist[v][next_step] > w + cost){
                    dist[v][next_step] = w + cost;
                    q.push(node(v,dist[v][next_step],next_step));
                   // printf("---%d %d %d\n",v,w,next_step);
                }
            }
        }
        int mx = big;
        for(int i = 0;i<=K+1;i++){
            mx = min(mx,dist[dst][i]);
           printf("i = %d -- %d\n",i,dist[dst][i]);
        }
        return mx<big?mx:-1;
    }
};

int main()
{
    int n=3;
    vector<vector<int> > flights{ { 0,1,100 }, { 1,2,100 }, { 0,2,500 } };
    int src = 0;
    int dst = 2; 
    int K = 0;
    Solution sol;
    sol.findCheapestPrice( n,  flights,  src,  dst, K);
    return 0;
}