#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> cur(m, 0), prv(m, 0);
        int length = 0;
        for (int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++){
                if (!i || !j || matrix[i][j]=='0'){
                    cur[j] = matrix[i][j] - '0';
                }else {
                    cur[j] = min(prv[j - 1], min(prv[j], cur[j-1])) + 1;
                }
                length = max(length, cur[j]);
            }
            fill(prv.begin(), prv.end(), 0);
            swap(prv, cur);
        }
        return length * length;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
