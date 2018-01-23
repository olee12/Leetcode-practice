#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i = 0;i<nums.size();i++){
            q.push(-1*nums[i]);
            if(q.size()>k) q.pop();
        }
        return -1*q.top();
        
    }
}; 

int main()
{
    
}