#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i]) nums[st++] = nums[i];
        }
        for(int i = st;i<nums.size();i++) nums[i] = 0;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
