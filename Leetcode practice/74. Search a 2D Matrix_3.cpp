#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row * col - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int r = mid / col;
            int c = mid % col;
            if (matrix[r][c] >= target) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        if (low >= row * col) return false;
        return matrix[low/col][low%col] == target;
    }
};


int main() {
    vector < vector<int> > matrix = {
        {1 }
    };

    int target = 2;;
    Solution sol;

    printf("result: %d\n", sol.searchMatrix(matrix, target));
}