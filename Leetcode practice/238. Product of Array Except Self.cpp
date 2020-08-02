#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        int p = 1;
        for(int num : nums) {
            ret.push_back(p);
            p *= num;
        }
        int right = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ret[i] *= right;
            right *= nums[i];
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> inp = {1,2,3,4};
    Solution sol;
    for(int it : sol.productExceptSelf(inp)){
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}
