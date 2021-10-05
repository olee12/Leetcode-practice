#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int tx = tree[0];
        int ty = tree[1];
        int sx = squirrel[0];
        int sy = squirrel[1];
        vector<int> dist(nuts.size(), 0);
        int total = 0;
        for (int i = 0; i < nuts.size(); i++) {
            dist[i] = abs(tx - nuts[i][0]) + abs(ty - nuts[i][1]);
            total += (2 * dist[i]);
        }
        int ret = numeric_limits<int>::max();
        for (int i = 0; i < nuts.size(); i++) {
            int x = abs(sx - nuts[i][0]) + abs(sy - nuts[i][1]);
            int nx = total - dist[i] + x < ret;
            if (nx < ret) ret = nx;
        }
        return ret;
    }
};