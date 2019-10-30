#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size() + 1;
        int sum = 0;
        int i = 0, j = 0;

        while(j < nums.size()) {
            sum += nums[j++];

            while(sum >= s) {
                len = min(len, j - i);
                sum-=nums[i++];
            }
        }
        if(len == nums.size()+1) return 0;
        return len;
    }
};

int main() {

}