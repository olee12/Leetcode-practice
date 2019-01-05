#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long mod = 1000000007;
const int maxn = 101;
int dp[maxn][maxn][maxn];





class Solution {
public:
    vector<int> group;
    vector<int> profit;
    int P;
    int G;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        this->group = group;
        this->profit = profit;
        this->P = P;
        this->G = G;
        memset(dp,-1,sizeof(dp));
        return rec(group.size()-1,0,0);
    }
    int rec(int pos,int point,int people)
    {
       // printf("%d %d %d\n",pos,point,people);
        if(pos == -1) return (point >= P) && (people <= G);
        if(people > G) return 0;
        int &ret = dp[pos][point][people];
        if(ret != -1) return ret;

        ret = 0;

        ret += rec(pos-1,point + profit[pos],people + group[pos]);
        ret %= mod;

        ret += rec(pos-1,point,people);
        ret %= mod;
        return ret; 
    }
};
int main()
{
    vector<int> group = {2,3,5};
    vector<int> profit = {6,7,8};
    int P = 5;
    int G = 10;

    Solution sol;

    printf("ret = %d\n",sol.profitableSchemes(G,P,group,profit));

    return 0;
}