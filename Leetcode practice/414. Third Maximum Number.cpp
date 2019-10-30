#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int mx1 = numeric_limits<int>::min();        
        int mx2 = numeric_limits<int>::min();        
        int mx3 = numeric_limits<int>::min();        
        for(int &num : nums) {
            if(num > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = num;
            }else if(num > mx2) {
                mx3 = mx2;
                mx2 = num;
            }else if(num > mx3) {
                mx3 = num;
            }
        }
        printf("mx1 = %d, mx2 = %d, mx3 = %d\n", mx1, mx2, mx3);
        int ret = mx3;
        if(mx3 == numeric_limits<int>::min()) ret = mx1;
        // else if(mx2 != numeric_limits<int>::min()) ret = mx2;
        // else if(mx1 != numeric_limits<int>::min()) ret = mx1;
        return ret;
    }
};

int main() {
    vector<int>  vec = {1,2};
    Solution sol;
    printf("sol: %d\n", sol.thirdMax(vec));
}