#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int inf = 1 << 25;
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
	return btup(coins, amount);
        int ret = rec(0, amount, coins, dp);
        return ret >= inf ? -1:ret;
    }

    int btup(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, inf);
	dp[0] = 0;
	sort(coins.begin(), coins.end());
	for(int i = 0;i<coins.size();i++){
	    for(int j = coins[i];j<=amount;j++){
		    if (dp[j - coins[i]] <= inf) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		    } 
	    }
	}
	if (dp[amount]>=inf) return -1;
	return dp[amount];
    }

    int rec(int pos, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount <= 0) {
            return (amount == 0)?0:inf;
        }
        if (pos == coins.size()) {
            return (amount == 0)?0:inf;
        }
        int &ret = dp[pos][amount];
        if (ret != -1) return ret;
        ret = rec(pos, amount - coins[pos], coins, dp) + 1;
        ret = min(ret, rec(pos + 1, amount, coins, dp));
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    int amount =  11;
    assert((new Solution())->coinChange(coins, amount)==3);
    return 0;
}
