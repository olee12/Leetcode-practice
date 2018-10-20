#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,'1');
                    cnt++;
                }
            }
        }
        return cnt;
    }
    private:
    void dfs(vector< vector<char> >& grid,int x,int y,char ch){
        if(grid[x][y] == ch) grid[x][y] = '.';
        else return;

        if(x+1 < grid.size()) dfs(grid,x+1,y,ch);
        if(y+1 < grid[0].size()) dfs(grid,x,y+1,ch);
        if(x-1 >= 0) dfs(grid,x-1,y,ch);
        if(y-1 >= 0) dfs(grid,x,y-1,ch);
    }
};

int main()
{

}
