#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ret;
        vector<int>::iterator beg = lower_bound(nums.begin(), nums.end(), target);

        if ( (nums.size()==0) || (beg == nums.end()) || (*beg!=target))
        {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }

        vector<int>::iterator end = upper_bound(nums.begin(), nums.end(), target);
        end--;

        ret.push_back(beg - nums.begin());
        ret.push_back(end - nums.begin());
        return ret;
    }
};

int main()
{
}