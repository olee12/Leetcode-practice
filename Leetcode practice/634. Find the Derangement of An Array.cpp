#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // vector<long long> dp;
    const int mod = 1000000007;
    int findDerangement(int n) {
        return veryFast(n);
        // dp.reserve(1000002);
        // fill(dp.begin(), dp.begin() + n + 1, 0);
        // dp[0] = 0;
        // dp[1] = 0;
        // dp[2] = 1;
        // for (int i = 3; i <= n; i++) {
        //     dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        //     dp[i] = (dp[i] * (i - 1)) % mod;
        // }
        // return dp[n];
        // return rec(n);
    }
    int veryFast(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        long long x = 0;
        long long y = 1;
        long long ret = 1;
        for (int i = 3; i <= n; i++) {
            ret = (x + y);
            ret = (ret * (i - 1)) % mod;
            x = y;
            y = ret;
        }
        return ret;
    }
    // long long rec(int n) {
    //     if (n == 1) return 0;
    //     if (n == 2) return 1;
    //     long long &ret = dp[n];
    //     if (ret != -1) return ret;
    //     long long x = (rec(n - 1) + rec(n - 2)) % mod;
    //     ret = (x * (n - 1)) % mod;
    //     return ret;
    // }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    cout << sol.findDerangement(4) << endl;
    /* code */
    return 0;
}
