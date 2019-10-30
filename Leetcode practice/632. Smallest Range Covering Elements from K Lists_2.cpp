#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vi;
        struct comp {
            bool operator() (pair<vi,vi> p1, pair<vi, vi> p2) {
                return *p1.first > *p2.first;
            }
        };
        priority_queue<pair<vi,vi>, vector<pair<vi,vi>>, comp > q;
        int mn = numeric_limits<int>::max(), mx = numeric_limits<int>::min();
        for(vector<int> &vec : nums) {
            q.push({vec.begin(), vec.end()});
            mn = min(mn, vec[0]);
            mx = max(mx, vec[0]);
        }
        vector<int> ans = {mn, mx};
        int range = numeric_limits<int>::max();
        while(true) {
            auto top = q.top();
            q.pop();
            if(mx - *top.first < range) {
                ans = {*top.first, mx};
                range = mx - *top.first;
            }
            top.first++;
            if(top.first == top.second) break;
            mx = max(*top.first, mx);
            q.push(top);
        }
        return ans;
    }
};


int main()
{
    // vector<vector<int>> nums = {{-73, -70, 15, 36, 51, 52}, {22, 44, 58, 60, 61}, {-61, 12, 21, 22, 23, 23, 25, 29}, {-27, -12, 1, 4, 18, 18, 18, 19}, {-1, 57, 58, 60, 69, 72, 73}, {13, 16, 41, 54, 88, 88, 89, 92}, {-16, 35, 39, 39, 43, 46}, {-16, 32, 35, 49, 54, 63}, {25, 49, 61, 68, 71}, {67, 88, 88, 90, 90, 90, 91}};

    vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};

    // vector<vector<int>> nums = {
    //     {-5,-4,-3,-2,-1,1},
    //     {1 , 2, 3, 4, 5}};
    Solution sol;
    for (int &r : sol.smallestRange(nums))
    {
        printf(" { %d ] ", r);
    }
}