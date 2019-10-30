#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Solution { 
public:
    map<string, multiset<string> > adj;
    vector<string> result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj.clear();
        for( auto it: tickets) {
            if(it.size()!=2) continue; 
            adj[it[0]].insert(it[1]);
        }
        dfs("JFK");
        return vector<string>(result.rbegin(), result.rend());
    }
  
    void dfs(string u) {
        while(adj[u].size()) {
            string v = *adj[u].begin();
            adj[u].erase(adj[u].begin());
            dfs(v);
        }
        return result.push_back(u);
    }
};




int main() {

}