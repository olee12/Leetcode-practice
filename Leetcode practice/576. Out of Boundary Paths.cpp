#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
const int mod = 1000000000 + 7;
int dp[maxn][maxn][maxn];
int dx[] = {0,0,-1,+1};
int dy[] = {-1,+1,0,0};
class Solution {
public:
    int row,col;

    int findPaths(int m, int n, int N, int i, int j) {
        memset(dp, -1, sizeof (dp) );
        this->row = m;
        this->col = n;
        return rec(i,j,N-1);
    }
    int rec(int x, int y, int k) {
        if(x < 0 || x >= row || y<0 || y >= col) {
            return 1;
        }
        if (k < 0) return 0;

        int &ret = dp[x][y][k];
        if (ret != -1) {
            return ret;
        }
        ret = 0;
        long long tmp = 0;
        for(int i = 0;i<4;i++) {
            tmp += rec(x + dx[i], y + dy[i], k -1);
            tmp %= mod;
        }
        ret = tmp;
    }
};



int main() {

}