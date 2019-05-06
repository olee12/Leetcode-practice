#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        if (row == 0) {
            return ;
        }
        int col = matrix[0].size();
  

        int flag = 1;


        for(int i = 0;i<row;i++) {
            if(matrix[i][0]==0) flag = 0;
            for(int j = 1;j<col;j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1;i<col;i++) {
            if (matrix[0][i] == 0) {
                for(int j = 0;j<row;j++) { matrix[j][i] = 0; }
            }
        }
        for(int i = 0;i<row;i++){
            if (matrix[i][0] == 0) {
                for(int j = 0;j<col;j++) matrix[i][j] = 0;
            }
        }

       
       if (flag == 0) {
                for(int j = 0;j<row;j++) matrix[j][0] = 0;
       }


    }
};
/**
 * 
[[0,1,2,0],
 [3,4,5,2],
 [1,3,1,5]]
 * 
 * */
int main(){

    return 0;
}