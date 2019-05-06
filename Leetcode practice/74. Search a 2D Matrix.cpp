#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * 
 * matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return false;
        int cols = matrix[0].size();
        if(cols==0) return false;

        int low = 0;
        int high = rows * cols - 1;

        while(low <= high) {
            // printf("low = %d, high = %d\n",low,high);
            int mid = (low + high) / 2;
            int r = mid / cols;
            int c = mid % cols;
            if(matrix[r][c] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(low > rows*cols-1 || low < 0) return false;
        return matrix[low / cols][low % cols] == target;
    }
};
int main() {
    vector<vector<int> > matrix = {
  {1}
    } ;
    Solution sol;
    printf("ret = %d\n",sol.searchMatrix(matrix,2));

}