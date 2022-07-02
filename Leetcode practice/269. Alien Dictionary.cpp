#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char> > graph;
        for(auto w:words) for(char ch:w) graph[ch];
        for(int i = 1;i<words.size();i++) {
            string &a = words[i-1];
            string &b = words[i];
            if(b.size() < a.size() && a.substr(0, b.size()) == b) return "";
            int x = 0;
            int m = min(a.size(), b.size());
            for(int x = 0;x < m; x++) {
                char u = a[x];
                char v = b[x];
                if(u == v) {
                    continue;
                }
                graph[u].push_back(v);
                break;
            }
            
        }

        unordered_map<char, int> visited;
        stack<char> st;
        for(auto &it:graph) {
            visited[it.first] = 0;
        }
        for(auto &it:graph) {
            if(visited[it.first] == 0 ) {
                if(dfs(it.first, graph, visited, st)) return "";                
            }
        }
        string ret = "";
        while (st.size())
        {
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
    }

    bool dfs(char u, unordered_map<char, vector<char>> &graph,  unordered_map<char,int> &visited, stack<char> &st) {
       if (visited[u] == 1) return true; 
       visited[u] = 1;
       for(char v: graph[u]) {
           if (visited[v]!=2 && dfs(v, graph, visited,st)) return true;
       }
       st.push(u);
       visited[u] = 2;
       return false;
    }
};