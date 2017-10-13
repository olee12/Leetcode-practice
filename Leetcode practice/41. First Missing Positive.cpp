#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        if(nums.size()==0) return 1;
        
        int n = findPvote(nums) + 1;

        for (int i = 0; i < n; i++)
        {
            // printf("++ %d %d ++\n",i,nums[i]);
            if (abs(nums[i]) <= n)
            {
                // printf("-- %d --\n",nums[i]);
                nums[abs(nums[i]) - 1] =  nums[abs(nums[i]) - 1] < 0? nums[abs(nums[i]) - 1] : nums[abs(nums[i]) - 1]*-1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return n+1;
    }

    int findPvote(vector<int> &nums)
    {
        int pt = -1;
        int pval = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > pval)
            {
                pt++;
                swap(nums[i], nums[pt]);
            }
        }
        
        return pt;
    }
};

int main()
{
    vector<int> vec;
    // vec.push_back(-10);
    vec.push_back(-1);
     vec.push_back(-2);
    // vec.push_back(-7);
    // vec.push_back(-6);
    // vec.push_back(-1);
    // vec.push_back(-5);
    int target = -8;
    Solution *sol = new Solution;
    printf("missing : %d\n",sol->firstMissingPositive(vec));
}