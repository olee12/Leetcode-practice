#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
       vector<int> dp(s.size() + 1, -1);
    //    return rec(0, s, dp);
       return iter(s);
    }
    int rec(int pos, const string &s, vector<int> &dp) {
        if (pos == s.size() ) return 1;
        int &ret = dp[pos];
        if(ret != -1) return ret;
        ret = 0;
        if(s[pos]=='0') return ret;
        ret += rec(pos+1, s, dp);
        if(pos + 1 <  s.size()) {
            if (s[pos]<'2')
                ret += rec(pos+2, s, dp);
            else if(s[pos]=='2' && s[pos+1]<='6') 
                ret += rec(pos+2, s, dp);
        }
        return ret;
    }
    int iter(const string &s) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0]!='0';
        for(int i = 2; i < dp.size();i++){
            if(s[i-1]!='0') {
                dp[i] += dp[i - 1];
            }
            string st = s.substr(i-2,2);
            int val = atoi(st.c_str());
            if(val >= 10 && val <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }


};

void testSolution() {
    Solution sol;
    string test1 = "12";
    printf("test: %s, ret: %d\n",test1.c_str(), sol.numDecodings(test1) );
    string test2 = "22611";
    printf("test: %s, ret: %d\n",test2.c_str(), sol.numDecodings(test2) );
    
}

int main() {

    testSolution();

    return 0;

}