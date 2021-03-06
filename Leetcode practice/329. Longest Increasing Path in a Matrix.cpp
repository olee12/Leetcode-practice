#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        vector<vector<int> > grid(n+2, vector<int> (m+2, numeric_limits<int>::min()));
        vector<vector<int> > degree(n+2, vector<int> (m+2, 0));
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                grid[i][j] = matrix[i-1][j-1];
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++) {
                for(int k = 0;k<4;k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if(grid[tx][ty] > grid[i][j]) degree[i][j]++;
                }
            }
        }
        
        vector<pair<int,int>> levels;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++) {
                if(degree[i][j] == 0) levels.push_back({i,j});
            }
        }

        vector<pair<int, int> > nextLevel;
        int height = 0;
        while(levels.size()) {
            nextLevel.clear();
            for (auto it : levels)
            {
                for (int i = 0; i < 4; i++)
                {
                    pair<int, int> nt = {it.first + dx[i], it.second + dy[i]};
                    if (grid[it.first][it.second] > grid[nt.first][nt.second])
                    {
                        degree[nt.first][nt.second]--;
                        if (degree[nt.first][nt.second] == 0)
                            nextLevel.push_back(nt);
                    }
                }
            }
            height++;
            printf("level: ");
            printVec(levels);
            printf("nextLevel: ");
            printVec(nextLevel);
            swap(levels, nextLevel);
            // return 0;
        }
        return height;
    }
    void printVec(vector<pair<int,int>>& nums) {
        printf("[");
        for(auto it:nums) {
            printf("{%d %d} ", it.first, it.second);
        }
        printf("]\n");
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {

        {9, 9, 4}, 
        {6, 6, 8}, 
        {2, 1, 1}
    };
    Solution sol;
    assert(sol.longestIncreasingPath(matrix)==4);
    /* code */
    return 0;
}
