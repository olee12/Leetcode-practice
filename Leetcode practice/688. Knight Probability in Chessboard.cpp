#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn = 26;
const int maxk = 101;
double dp[maxn][maxn][maxk];
int dx[] = {+2, +1, -1, -2, +2, +1, -1, -2};
int dy[] = {+1, +2, +2, +1, -1, -2, -2, -1};
class Solution {
public:
    int _N,_K;
    double knightProbability(int N, int K, int r, int c) {
        _N = N;
        _K = K;
        for(int i = 0;i<=N;i++){
            for(int j = 0; j<=N;j++) {
                for(int k = 0;k<=K;k++) {
                    dp[i][j][k] = -1; 
                }
            }
        }
        double ret = rec(r,c,0);
        return ret;
    }
    double rec(int x, int y, int k) {
        if (x < 0 || x >= _N || y < 0 || y >= _N) {
            return 0;
        }
        if(k == _K) return 1;
        double &ret = dp[x][y][k];
        if( !(ret < 0) ) return ret;
        ret = 0;
        for(int i = 0;i<8;i++){
            ret += rec(x + dx[i], y + dy[i], k + 1);
        }
        ret = ret/8.;        
        return ret;
    }
};


int main() {
    int N = 3;
    int K = 2;
    int r = 0, c = 0;
    Solution sol;
    printf("%lf\n",sol.knightProbability(N,K,r,c));
}