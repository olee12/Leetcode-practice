#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector< vector< vector<int> > > dp(nums.size(),vector< vector<int> >(2, vector<int>(2,-1)));
        return rec(0,0,0,nums,dp);
    }
    int rec(int pos,int first,int prev, vector<int> &nums, vector< vector< vector<int> > > &dp) {
        if(pos == nums.size()) {
            return 0;
        }
        int &ret = dp[pos][first][prev];
        if (ret != -1) return ret;
        if( (( (pos == nums.size()-1) && first) == false) && prev==false) {
            ret = max(ret, rec(pos+1,first || pos == 0, true, nums, dp) + nums[pos]);
        }
        ret = max(ret, rec(pos+1,first,false,nums,dp));
        return ret;
    }
};


int main() {
    vector<int> nums = {7};
    Solution sol;
    cout<<"result: "<<sol.rob(nums)<<endl;
}