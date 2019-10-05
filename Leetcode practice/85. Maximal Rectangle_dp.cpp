#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
	int row, col;
	if ((row=matrix.size())==0 || (col=matrix[0].size())==0){
		return 0;
	}
	vector<int> left(col,0);
	vector<int> right(col,col);
	vector<int> height(col,0);
	
	int ret = 0;
	for(int i = 0;i<row;i++) {
		int cleft = 0, cright = col, cheight = 0;
		for(int j = 0;j<col;j++){
			if(matrix[i][j] == '1') height[j]++;
			else {height[j] = 0;}
		}
		for(int j = 0;j<col;j++){
			if(matrix[i][j] == '1') left[j] = max(left[j],cleft);
			else {left[j] = 0;cleft=j+1;}
		}
		for(int j = col-1;j>=0;j--){
			if(matrix[i][j] == '1') right[j] = min(right[j],cright);
			else {right[j] = col;cright=j;}
		}

		for(int j = 0;j<col;j++){
			ret = max(ret, (right[j] - left[j])*height[j]);
		}
	}
   	return ret;
    }
};

int main() {

}
