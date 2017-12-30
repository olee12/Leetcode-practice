#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        int mid;
        while(low < high){
             mid = (low + high) / 2;
            if(nums[mid] > nums[high]){
                low = mid + 1; 
            }else{
                high = mid;
            }
        }
        return nums[low];

    }
};


int main()
{
    vector<int> vec;
    
    
   
    vec.push_back(0);
    
   
    printf("%d\n",(new Solution)->findMin(vec));
}