#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        maxProfitO1(prices);
        int n = prices.size();
        if (n == 0)
            return 0;

        int dp[n + 1][2][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1][1] = -1e8;

        for (int i = 1; i <= n; i++)
        {
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i - 1]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][1][0] - prices[i - 1]);
        }

        return dp[n][1][0];
    }

    int maxProfitO1(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        int dpik0 = 0;
        int dpik1 = numeric_limits<int>::min();
        int dpik0_pre = 0;
        for (int i = 0; i < n; i++)
        {
            int dpik0_old = dpik0;
            dpik0 = max(dpik0, dpik1 + prices[i]);
            dpik1 = max(dpik1, dpik0_pre-prices[i]);
            dpik0_pre = dpik0_old;
        }

        return dpik0;
    }
};


int main()
{

}