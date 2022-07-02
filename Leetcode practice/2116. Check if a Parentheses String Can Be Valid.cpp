#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2) return false;
        int tot = 0, op = 0, cl = 0;
        
        for(int i = s.size() - 1;i>=0;i--) {
            if(locked[i] == '0') tot++;
            else if(s[i] == '(') op++;
            else if(s[i] == ')') cl++;
            if((tot + cl - op ) < 0 )
                return false;
        }
        
        tot = 0; op = 0;cl = 0;
        for(int i = 0;i<s.size();i++) {
            if(locked[i] == '0') tot++; 
            else if(s[i] == '(') op++;
            else cl++;
            if((tot + op - cl) < 0) return false;
        }
        return true;
    }
};
/*
"())()))()(()(((())(()()))))((((()())(())"
"1011101100010001001011000000110010100101"
*/
int main(int argc, char const *argv[])
{

    string s = "())()))()(()(((())(()()))))((((()())(())";
    string l = "1011101100010001001011000000110010100101";

    Solution sol;
    cout << sol.canBeValid(s, l) << endl;
    /* code */
    return 0;
}
