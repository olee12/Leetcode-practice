#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        vector<int> ret;       
        for(int i = 0;i<nums.size();i++) {
            while(q.size() && q.back().first <= nums[i]) q.pop_back();
            q.push_back({nums[i],i});
            while(q.front().second <= (i-k)) q.pop_front();
            if(i + 1 >= k) ret.push_back(q.front().first);
        }
        return ret;
    }
};



int main() {
    vector<int> vec = {1,3,-1,-3, 5,3,6,7};
    Solution sol;
    for(int &a : sol.maxSlidingWindow(vec, 3)) {
        printf("%d ",a);
    }
    printf("\n");
    return 0;
}