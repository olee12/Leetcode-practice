#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int low = 1;
        int high = nums.size();
        
        while(low <= high){
            int mid = (low + high) / 2;

            if(count_nums(nums,mid) <= mid){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return low;

    }

    int count_nums(vector<int> &nums,int val){
        int cnt = 0;
        for(int &a:nums){
            if(a<=val)
                cnt++;
        }
        return cnt;
    }
    
};


int main()
{

    return 0;
}
