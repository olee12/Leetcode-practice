#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>

using namespace std;

const int node = 103;
const int lap = 203;
const int INF = 1e9 + 7;

vector<int> graph[node], score(node), total_sub_node(node, 0);
vector< vector<int> > cost_without_me(node, vector<int>(lap, 0)), double_lap(node, vector<int>(lap, 0)), have_single(node, vector<int>(lap, 0));

void reset()
{
    for(int i=0; i<node; i++)
    {
        graph[i].clear();
        score[i] = 0;
        cost_without_me[i] = vector<int>(lap, 0);
        double_lap[i] = vector<int>(lap, -INF);
        have_single[i] = vector<int>(lap, -INF);
        total_sub_node[i] = 0;
    }
}

void dfs(int u, int p)
{
    if(graph[u].size() == 0 || (graph[u].size() == 1 && graph[u][0] == p))
    {
        double_lap[u][0] = score[u];
        have_single[u][0] = score[u];
        total_sub_node[u] = 1;
        return;
    }
    // cout << "dfs " << u << " " << p << endl;
    // cout<< "size " << graph[u].size() << " firstElement " << graph[u][0] << endl; 
    int pre = -1;
    double_lap[u][0] = score[u];
    have_single[u][0] = score[u];

    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];

        if(v == p)
            continue;

        dfs(v, u);

        for(int lap_it=total_sub_node[u]*2; lap_it>=0; lap_it--){
            cost_without_me[v][lap_it] = double_lap[u][lap_it];
            // cout<< "---------> cost without me " << v << " lap " << lap_it << " cost " << cost_without_me[v][lap_it] << endl;
        }

        int starting = total_sub_node[u] + total_sub_node[v];

        for(int lap_it=starting*2; lap_it>0; lap_it-=2)
        {
            for(int pre_taken=min(total_sub_node[u]*2, lap_it-2); pre_taken>=0; pre_taken-=2)
            {
                double_lap[u][lap_it] = max(double_lap[u][lap_it], double_lap[u][pre_taken]+double_lap[v][lap_it-pre_taken-2]);
            }
        }

        total_sub_node[u] += total_sub_node[v];
    }
    // cout << "left to right update completed " << endl;
    int pre_total_node = 0;
    vector<int> helper(2*total_sub_node[u]+3, 0);

    for(int i=graph[u].size()-1; i>=0; i--)
    {
        int v = graph[u][i];

        if(v == p)
            continue;

        int starting = total_sub_node[u] - total_sub_node[v];

        for(int lap_it=starting*2; lap_it>0; lap_it-=2)
        {
            for(int pre_taken=min((starting - pre_total_node)*2, lap_it-2); pre_taken>=0; pre_taken-=2)
            {
                cost_without_me[v][lap_it] = max(cost_without_me[v][lap_it], cost_without_me[v][pre_taken]+helper[lap_it-pre_taken]);
            }
        }
        // cout << "Cost without me calculated " << u << " " << v << endl;
        starting = total_sub_node[v] + pre_total_node;

        for(int lap_it=starting*2; lap_it>0; lap_it-=2)
        {
            for(int pre_taken=min(lap_it-2,pre_total_node*2); pre_taken>=0; pre_taken-=2)
            {
                helper[lap_it] = max(helper[lap_it],helper[pre_taken]+double_lap[v][lap_it-pre_taken-2]);
                // cout<< "double_lap lap " << lap_it-pre_taken-2 << " cost " << double_lap[v][lap_it-pre_taken-2] << endl;
                // cout<< "helper lap " << lap_it << " " << helper[lap_it] << endl;
            }
        }
        // cout<< "helper calculated completed " << u << " " << v  << endl;
        starting = total_sub_node[u];

        for(int lap_it=starting*2 -1; lap_it>0; lap_it--)
        {
            for(int double_taken=min(lap_it-1-((lap_it&1) == 0), (starting - total_sub_node[v])*2); double_taken>=0; double_taken-=2)
            {
                have_single[u][lap_it] = max(have_single[u][lap_it], cost_without_me[v][double_taken] + have_single[v][lap_it-double_taken-1]);
                // cout << u << " lap: " << lap_it << " doubleTaken: " << double_taken << " cost: " << have_single[u][lap_it] << endl;
                // cout<< cost_without_me[v][double_taken] << " having_single " << have_single[v][lap_it-double_taken-1] << endl;
            }
        }

        pre_total_node += total_sub_node[v];
        pre = v;

        // cout << "single calculated till v completed" << endl;
    }

    total_sub_node[u]++;
    // cout << "dfs completed " << u << " " << p << endl;
}


int main()
{
    int tcase, n, x;

    scanf("%d", &tcase);

    for(int cas=1; cas<=tcase; cas++)
    {
        reset();

        scanf("%d %d", &n, &x);

        x = min(x, 2*n);

        for(int i=1; i<=n; i++)
            scanf("%d", &score[i]);
        // cout<< "scores taken "<< n << endl;
        for(int i=1; i<n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
        // cout<< "--> " << u << " " << v << endl;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // cout<< "input taken completed" << endl;
        dfs(1, -1);

        int ans = score[1];

        for(int i=1; i<=x; i++)
            ans = max(ans, have_single[1][i]);

        printf("Case %d: %d\n",cas, ans);
    }

    return 0;
}

/*
1
4 4
1 4 2 3
1 2
1 3
3 4
*/