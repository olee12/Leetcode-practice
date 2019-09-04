#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 1) return s;
        string ret = s;
        int len = 0;
        // printf(" [");
        for(int i = 0;i<numRows;i++){
            int fg = numRows - i - 1;
            int sg = i;
            int indx = i;
            int prev = -1;
            while(indx < s.size()) {
                // printf(" (%d)(%d)",prev,indx);
                if(prev!=indx)
                    ret[len++]= s[indx];
                prev = indx;
                indx += fg * 2;
                swap(fg,sg);
                
            }
        }
        // printf("] ");
        return ret;
    }
};


int main() {
    string str = "PAYPALISHIRING";
    Solution sol;
    cout<<sol.convert(str,4)<<endl;
}