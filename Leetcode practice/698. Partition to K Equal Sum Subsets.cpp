#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
char dp[1<<16][16];
int smap[1<<16];
class Solution
{
  public:
    int go = 0;
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        memset(dp,-1,sizeof(dp));
        go = 0;
        for (int a : nums)
        {
            go += a;
        }
        if (go % k)
            return false;
        go/=k;
        for(int mask = (1<<nums.size()) - 1;mask>=0;mask--){
            int sum = 0;
            for(int i = 0;i<nums.size();i++){
                if(mask & (1<<i)) sum+=nums[i]; 
            }
            smap[mask] = sum;
        }
        return rec((1 << nums.size()) - 1, k - 1, nums);
    }

    bool rec(int mask, int k, vector<int> &nums)
    {
        if (k == -1)
            return 1;

        char &ret = dp[mask][k];
        if (ret != -1)
            return ret;
            ret = 0;
        if (smap[mask] == go)
        {
            ret |= rec(0, k - 1, nums);
        }
        for (int p = mask - 1; (p ^ mask) > 0; p = (p - 1) & mask)
        {
            if (smap[p] == go)
            {
                ret |= rec(p ^ mask, k - 1, nums);
            }
        }
        return ret;
    }
};
// [71,85,99,110,27,47,8,83,72,24,52,17,99]
// 13
int main()
{
//     [4,3,2,3,5,2,1]
// 4
    vector<int> inp = vector<int>{4,3,2,3,5,2,1};
    Solution sol;
    printf("ret: %d", sol.canPartitionKSubsets(inp, 3));
}