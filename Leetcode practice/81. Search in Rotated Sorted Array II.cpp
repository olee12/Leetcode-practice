
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;

        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid]==target) return true;
            
            if(nums[low]==nums[mid] && nums[mid]==nums[high]) low++,high--;
            
            else if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target<nums[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            else if(target>=nums[mid] && target<= nums[high]){
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }
        return false;
    }
};

int main()
{
    
}