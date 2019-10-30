#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size()==0) return 0;
        int row = matrix.size(), col = matrix[0].size();

        int i = 0;
        int j = col-1;
        while(i<row && j>-1) {
            if(matrix[i][j] == target) return true;
            // printf("i: %d, j: %d, ij: %d\n",i,j,matrix[i][j]);
            if(matrix[i][j] > target) j--;
            else i++;
        } 
        return false;
    }
};

int main() {
    vector < vector<int> > matrix = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
        };


    int target = 19;
    Solution sol;

    printf("result: %d\n", sol.searchMatrix(matrix, target));
}


