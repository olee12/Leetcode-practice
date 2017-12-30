#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        if(nums.size()==0) return 0;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end())
        {
            return nums.size();
        }
        if (it == nums.begin() && *it != target)
        {
            return 0;
        }
        return it - nums.begin();
    }
};

int main()
{
    return 0;
}