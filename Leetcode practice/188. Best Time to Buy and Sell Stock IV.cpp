#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxProfit(int K,vector<int> &prices)
    {
        
        int n = prices.size();
        
        if (n == 0)
            return 0;
        if(K>=n/2){
            return maxProfitO1(prices);
        }
        vector<int> dpik0(K+1,0);
        vector<int> dpik1(K+1,numeric_limits<int>::min());

        for (int i = 1; i <= n; i++)
        {
            for (int k = K; k >= 1; k--)
            {
                dpik0[k] = max(dpik0[k], dpik1[k] + prices[i - 1]);
                dpik1[k] = max(dpik1[k], dpik0[k-1]  - prices[i - 1]);
            }
        }

        return  dpik0[K];
    }

    int maxProfitO1(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        int dpik0 = 0;
        int dpik1 = numeric_limits<int>::min();

        for (int i = 0; i < n; i++)
        {
            int dpik0_old = dpik0;
            dpik0 = max(dpik0, dpik1 + prices[i]);
            dpik1 = max(dpik1, dpik0_old - prices[i]);
        }

        return dpik0;
    }
};

int main()
{
}