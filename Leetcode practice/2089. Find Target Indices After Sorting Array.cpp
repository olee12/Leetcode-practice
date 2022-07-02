#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       int lesseer = count_if(begin(nums), end(nums), [&](int n) {return n < target;});
       int equal = count(begin(nums), end(nums), target);
       vector<int> ret(equal);
       iota(begin(ret), end(ret), lesseer);
       return ret;
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> nums= {1,2,5,2,3};
    int target = 2;
    Solution sol;
    cout << sol.targetIndices(nums, target)[0] << " "<< sol.targetIndices(nums, target)[1]<<endl;
    return 0;
}
