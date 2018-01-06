#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return uniquePathsWithObstaclesOn(obstacleGrid);
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector< vector<int> > dp(obstacleGrid);
        dp[0][0] ^= 1;

        for(int i = 1;i<m;i++) dp[0][i] = dp[0][i] ? 0: dp[0][i-1];
        for(int i = 1;i<n;i++) dp[i][0] = dp[i][0] ? 0: dp[i-1][0];

        for(int i = 1;i<n;i++)
            for(int j = 1;j<m;j++)
                dp[i][j] = obstacleGrid[i][j] ? 0: dp[i-1][j] + dp[i][j-1];
        
        return dp[n-1][m-1];
    }

    int uniquePathsWithObstaclesOn(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(m,0);
        dp[0] = 1;
        for(vector<int> &row : obstacleGrid){
            for(int j = 0;j<m;j++)
            if(row[j]==1)
                dp[j] = 0;
            else if(j > 0)
                dp[j] = dp[j] + dp[j-1];
        }
        return dp[m-1];
    }
};


int main()
{
    Solution sol;
    //int ret = sol.uniquePathsWithObstacles(8,3);

}