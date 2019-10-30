#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        vector<int> &A = nums1;
        vector<int> &B = nums2;
        int m = A.size();
        int n = B.size();

        int imin = 0, imax = m;
        int half = (m+n+1) / 2;

        while (imin <= imax)
        {
            int i = (imin + imax) / 2;
            int j = (half - i);
            if( i < m && B[j-1] > A[i]) {
                imin = i + 1;
            }else if(i > 0 && A[i-1] > B[j]) {
                imax = i - 1;
            } else {
                int max_of_left = 0, min_of_right = 0;
                if(i == 0) max_of_left = B[j - 1];
                else if (j == 0) max_of_left = A[i - 1];
                else max_of_left = max(A[i - 1], B[j - 1]);

                if((n+m) % 2) return max_of_left;

                if (i == m) min_of_right = B[j];
                else if(j==n) min_of_right = A[i];
                else min_of_right = min(A[i], B[j]);

                return (max_of_left + min_of_right) / 2.;
            }
        }
        

    }
};


int main() {
    Solution sol;

    vector<int> num1 = {7, 8};
    vector<int> num2 = {6, 10, 10, 13, 15, 17, 20};

    printf("%lf\n", sol.findMedianSortedArrays(num2, num1));
}