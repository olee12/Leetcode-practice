#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_map<int,int> valid;
        stack<int> st;
        for(int i = 0;i<s.size();i++) {
            if(isalpha(s[i])) {
                continue;
            }
            if(s[i] == '(') {
                st.push(i);
                continue;
            }
            if(st.size()) {
                valid[st.top()] = 1;
                valid[i] = 1;
                st.pop();
            }
        }
        string ret = "";
        for(int i = 0;i<s.size();i++) {
            if(isalpha(s[i])) ret.push_back(s[i]);
            else if(valid.count(i) == 1) ret.push_back(s[i]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.minRemoveToMakeValid("))((")<<endl;
    
    return 0;
}
