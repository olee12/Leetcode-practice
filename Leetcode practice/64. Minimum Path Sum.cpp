#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        vector< vector<int> > dp(grid.size(),vector<int>(grid[0].size(),-1));

        return rec(0,0,dp,grid);
    }

    int rec(int i,int j,vector<vector<int> > &dp,vector< vector<int> > &grid) {
        if(i== grid.size() - 1 && j == grid[0].size() -1 ) return grid[i][j];

        int &ret = dp[i][j];
        if(ret != -1) return ret;
        ret = (1<<29);

        if(i + 1 < grid.size()) ret = min(rec(i+1,j,dp,grid) + grid[i][j],ret );
        if(j + 1 < grid[0].size()) ret = min(rec(i,j+1,dp,grid) + grid[i][j] , ret);

        return ret;
    }

};



int main()
{
    vector<vector<int> > grid = {
        {1,3,1},{1,5,1},{4,2,1}
    };
    Solution sol;
    printf("ret = %d\n",sol.minPathSum(grid));
    return 0;
}