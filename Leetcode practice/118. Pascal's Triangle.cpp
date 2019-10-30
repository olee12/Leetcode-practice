#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > pascal;
        if(numRows == 0) return pascal;
        vector<int> row;
        row.push_back(1);
        pascal.push_back(row);
        for(int row = 1;row<numRows;row++){
            vector<int> comb = pascal.back();
            comb.push_back(0);
            for(int i = comb.size()-1;i>=1;i--){
                comb[i] = comb[i] + comb[i-1];
            }
            pascal.push_back(comb);
        }
        return pascal;
    }
};
int main() {

}