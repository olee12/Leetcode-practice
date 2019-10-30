#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        //return getCleanString(S) == getCleanString(T);
        return complexSolution(S,T);
    }
    string getCleanString(string str) {
        int ptr = 0;
        for(int i = 0;i<str.size();i++) {
            if(str[i]=='#'){ 
                ptr--;
                ptr = max(ptr, 0);
            }
            else {
                str[ptr++] = str[i];
            }
        }
        str.resize(ptr);
        return str;
    }
    bool complexSolution(string s, string t) {
        for(int i = s.size() -1, j = t.size()-1; ;j--,i--) {
            for(int back = 0;i>=0 && (back || s[i]=='#');i--) back += s[i]=='#' ? 1 : -1;
            
            for(int back = 0;j>=0 && (back || t[j]=='#');j--) back += t[j]=='#' ? 1 : -1;

            if ( i < 0 || j < 0 || s[i]!=t[j]) return i == -1 && j == -1;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string s = "ab#c";
    string t = "ad#c";
    cout<<(new Solution())->backspaceCompare(s,t)<<endl;
    return 0;
}
