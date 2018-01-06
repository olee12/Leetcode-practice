#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return threeSumClosestHelper(nums, target);
    }

    int threeSumClosestHelper(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int diff = numeric_limits<int>::max();
        int ret = 0;
        for(int i = 0;i<nums.size();i++){
            int sum = target - nums[i];

            int l = i + 1;
            int r = nums.size() - 1;

            while(l<r){
                int rem = nums[l] + nums[r];
                if(diff > abs(sum - rem)){
                    ret = nums[i] + rem;
                    diff = abs(sum - rem);
                }
                if(rem < sum) l++;
                else if(rem > sum) r--;
                else l++,r--;
            }
        }
        return ret;
    }


};

int main()
{

}