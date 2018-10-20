#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class compare{
    public:
    bool operator() (pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
           return a.second > b.second;
        }
        return a.first < b.first;
    }
};

class Solution {
public:
    //olee12
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,compare > q;
        vector<int> ret;
        for(int i = 0;i<nums.size();i++){
            q.push(make_pair(nums[i],i));
            if(i < k - 1) continue;
            while(q.size() && q.top().second < i - k + 1) q.pop();
            ret.push_back(q.top().first);
            //printf("pos: %d , max : %d, q.size: %d\n",i,q.top().first,q.size());
        }
        return ret;
    }
};

int main()
{

    vector<int> vec = {3,3,3,3,3,3,3,3,4,4,4,4,4,5,5,5,1,1,1,1};
    Solution sol;
    sol.maxSlidingWindow(vec,3);


}