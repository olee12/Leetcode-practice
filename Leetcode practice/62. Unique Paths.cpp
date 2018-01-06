#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int uniquePaths(int m, int n) {
        int ret = uniquePathsOn(m,n);
        return ret;
        vector< vector<int> > dp(m,vector<int>(n,1));
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
       // assert(ret!=dp[m-1][n-1]);
        return dp[m-1][n-1];
    }

    int uniquePathsOn(int m, int n) {
        vector< int > dp(n,0);
        dp[0] = 1;
        for(int i = 0;i<m;i++){
            for(int j = 1;j<n;j++){
                 dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }

};


int main()
{
    Solution sol;
    int ret = sol.uniquePaths(8,3);
}