#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<vector<vector<int>>> dp;
    int row, col;
    vector<vector<char>> g;
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid.size() == 0) return true;
       row = grid.size();
       col = grid[0].size(); 
       dp = vector< vector<vector<int> > > (row, vector<vector<int> >(col, vector<int>((row+col)/2 + 1, -1)));
        g = grid;
        return rec(0, 0, 0);
    }

    bool rec(int i, int j, int op) {
        if (i == row-1 && j == row-1) {
            if (op == 0) return true;
        }

        if (op > (row + col)/2) return false;
        int &ret = dp[i][j][op]; 
        if (ret != -1) return ret;
        if(i < row -1) {
            ret = rec(i+1, j,  op + ('('== g[i][j] ? +1 : -1));
            if (ret) return ret;
        }
        if(j < col -1) {
            ret = rec(i, j+1, ('('== g[i][j] ? +1 : -1));
        }
        return ret;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
