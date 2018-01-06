#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int mask = (1<<len) - 1;

        vector<vector<int> > ret;
        vector<int> result;
        ret.push_back(result);

        while(mask > 0){

            result.clear();
            for(int i = 0;i<len;i++)
                if(mask & (1<<i)) result.push_back(nums[i]);
            ret.push_back(result);
            mask--;
        }
        return ret;

    }
};


int main()
{

}