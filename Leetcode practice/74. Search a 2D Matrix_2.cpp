#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0){
            return false;
        }
        int low = 0;
        int high = matrix.size()-1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(matrix[mid][0] >= target) {
               high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        // printf("low: %d\n",low);
        if (low >= matrix.size()) low --;
        if (matrix[low][0]>target) low --;
        if (low < 0) return false;
        vector<int>::iterator it = lower_bound(matrix[low].begin(), matrix[low].end(), target);

        // printf("low: %d, val: %d, target: %d\n",low, *it, target);
        return (it != matrix[low].end()) && *it==target; 
    }
};

int main() {
    vector < vector<int> > matrix = {
        {1,3 }
    };

    int target = 3;
    Solution sol;

    printf("result: %d\n", sol.searchMatrix(matrix, target));
}


