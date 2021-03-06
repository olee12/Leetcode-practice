#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int splitArray(vector<int>& nums, int m) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(m+1, -1));
        return binarySolve(nums, m);
    }
    long long rec(int pos, int m, vector<int>& nums, vector<vector<long long>> &dp) {
        if (m == 0) {
            if (pos == nums.size()) return 0;
            return numeric_limits<int>::max();
        }
        if (pos >= nums.size()) {
            if (m) return numeric_limits<int>::max();
            return 0;
        }
        long long &ret = dp[pos][m];
        if (ret != -1) {
            return ret;
        }
        ret = numeric_limits<int>::max();
        long long sum = 0;
        for(int i = pos;i<nums.size();i++) {
            sum += nums[i];
            ret = min(ret, max(sum , rec(i+1, m-1, nums, dp)));
            // printf("---- pos: %d, i: %d, m: %d, sum: %lld, rec: %lld, ret: %lld\n", pos, i, m,  sum, rec(i+1, m-1, nums, dp), ret);
        }
        return ret;
    }

    int binarySolve(vector<int>& hight, int m) {
        long long high = 0;
        for(auto it: hight) high+=it;
        long long low = 1;

        while(low <= high) {
            long long mid = (low + high) / 2;
            printf("mid: %d, split: %d\n", mid, split(hight, m, mid));
            if (split(hight, m, mid)) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return low;

    }

    bool split(vector<int>& hight, int m, long long val) {
        int sum = 0;

        for(int i = 0;i<hight.size();i++){
            if(hight[i] > val) return false; 
            if ((sum + hight[i]) > val) {
                m--;
                sum = 0;
            }
            sum+=hight[i];
        }
        // if (m >= 1 && sum <= val) return true;
        return m>=1;

    }


};


int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> inp1 = {1,4,4}; 
    int m1 = 3;
    cout << sol.splitArray(inp1, m1)<<"\n";
    assert(sol.splitArray(inp1, m1)==9);

    /* code */
    return 0;
}
