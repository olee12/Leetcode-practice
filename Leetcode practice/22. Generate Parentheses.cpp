#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        ret = vector<string>();
        string str = "";
        rec(n,n,str);
        return ret;
    }
    void rec(int o, int c, string& str) {
        if (o==0 && c == 0) {
            ret.push_back(str);
            return ;
        }

        if (o) {
            str.push_back('(');
            rec(o-1, c, str);
            str.pop_back();
        }
        if (c > o) {
            str.push_back(')');
            rec(o,c-1,str);
            str.pop_back();                
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    auto ret = sol.generateParenthesis(3);
    for(auto vec : ret) {
        printf("[%s]\n",vec.c_str());
    }
    /* code */
    return 0;
}
