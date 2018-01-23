#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        int len = nums.size();
        
        for(int i = 0;i<len;i++)
        {
            if(nums[i]!=0)
                nums[start++] = nums[i];
        }
        while(start < len)
            nums[start++] = 0;
    }
};

int main()
{

}