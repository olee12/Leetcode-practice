#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
       return maxProfitO1(prices);
        int n = prices.size();
        if (n == 0)
            return 0;

        int dp[n + 1][2][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1][1] = -1e8;
        dp[0][0][1] = -1e8;

        for (int i = 1; i <= n; i++)
        {
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i - 1]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i - 1]);
        }

        return dp[n][1][0];
    }
    int maxProfitO1(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        int dpi10 = 0;
        int dpi11 = numeric_limits<int>::min();

        for (int i = 0; i < n; i++)
        {
            dpi10 = max(dpi10, dpi11 + prices[i]);
            dpi11 = max(dpi11, -prices[i]);
        }

        return dpi10;
    }
};

int main()
{
}