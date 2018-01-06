#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        return rec(nums,0,nums.size());
        int max_so_far, max_ending_here;
        max_so_far = max_ending_here = nums[0];

        for(int i = 1;i<nums.size();i++){
            if(max_ending_here < 0)
                max_ending_here = 0;
            max_ending_here+=nums[i];
            if(max_ending_here > max_so_far){
                max_so_far = max_ending_here;
            }
        }
         return max_so_far;
    }

    int rec(vector<int> &nums,int st,int end){

        if(st==end) return nums[st];

        int center = (st + end) / 2;

        int left = rec(nums,st,center);
        int right = rec(nums,1 + center,end);

        int sum = nums[center];
        int mxL = sum;
        for(int i = center -1 ; i>=st;i--){
            sum+=nums[i];
            if(sum > mxL) mxL = sum;
        }
        sum = nums[center+1];
        int mxR = sum;
        for(int i = center +2;i<=end;i++){
            sum+=nums[i];
            if(sum > mxR) mxR = sum;
        }

        int ret = max(left,right);
        ret = max(ret,mxR+mxL);
        return ret;
    }
   
};

int main()
{
    
}
