#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ret = 0;
        for(int i = 0; i < s.size();i++) {
            cout << i << " "<<st.size()<<endl; 
            if(s[i]=='(') {
                st.push(i);
                continue;
            }
            if(s[i] == ')') st.pop();
            if (st.size())
                ret = max(ret, i - st.top());
            if(st.size()==0) st.push(i);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.longestValidParentheses(")()())")<<endl;
    /* code */
    return 0;
}
