#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        for(int i = 0;i<len;i++){
            nums[start] = nums[i];
            while(nums[i]==nums[start]) i++;
            i--;
            start++;
        }
        return start;
    }
};


int main()
{
    
}
