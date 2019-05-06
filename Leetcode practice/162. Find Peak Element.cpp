#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return helper(nums,0,nums.size() - 1);
    }
    int helper(vector<int>& nums, int low,int high) {
        if(low == high) return low;
        int mid = (low + high) / 2;
        if(nums[mid] > nums[mid+1]){
            return helper(nums,low,mid);
        }else {
            return helper(nums,mid+1,high);
        }
    }
};

int main() {

}