#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int left = 0, right = nums.size() - 1;
        // int mid = 0;

        // while(mid <= right) {
        //     if (nums[mid] == 0) {
        //         swap(nums[left++],nums[mid++]);
        //     } else if (nums[mid] == 2) {
        //         swap(nums[mid],nums[right--]);
        //     } else {
        //         mid++;
        //     }
        // }        // int left = 0, right = nums.size() - 1;
        // int mid = 0;

        // while(mid <= right) {
        //     if (nums[mid] == 0) {
        //         swap(nums[left++],nums[mid++]);
        //     } else if (nums[mid] == 2) {
        //         swap(nums[mid],nums[right--]);
        //     } else {
        //         mid++;
        //     }
        // }

        int n2 = -1, n1 = -1, n0 = -1;

        for(int i = 0;i<nums.size();i++) {
            if (nums[i] == 0) {
                nums[++n2] = 2;
                nums[++n1] = 1;
                nums[++n0] = 0;

            } else if (nums[i] == 1) {
                nums[++n2] = 2;
                nums[++n1] = 1;
            } else {
                nums[++n2] = 2;
            }
        }
    }
};

int main() {
    vector<int> vec = {2,2,2,0,0,1,1};
    Solution sol;
    sol.sortColors(vec);
    for (int a : vec) {
        printf(" %d ",a);
    }
    printf("\n");
}