#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1000000007;
    int numDecodings(string s) {
        vector<long long> dp(s.size(), -1);
        return rec(0, s, dp);
    }

    long long rec(int pos, const string &s, vector<long long> &dp) {
        if (pos == s.size()) return 1;
        long long &ret = dp[pos];
        if(ret != -1) return ret;
        ret = 0;
        if(s[pos]=='0') return ret;
        ret = (s[pos]=='*' ? 9 : 1) * rec(pos + 1, s, dp);
        if(pos + 1 < s.size()) {
            if(s[pos]== '1') {
                ret += (s[pos+1]!='*'?1:9) * rec(pos + 2, s, dp);
            }else if(s[pos]=='2') {
                // printf("%s %d\n", s.c_str(), ret);
                if(s[pos+1]=='*') ret += 6 * rec(pos+2, s, dp);
                else if(s[pos+1]>='0' && s[pos+1]<='6') ret += rec(pos+2, s, dp); 
            }else if(s[pos]=='*') {
                if (s[pos+1]=='*') ret += 15 * rec(pos+2, s, dp);
                else if(s[pos+1]>='0' && s[pos+1] <='6') ret +=  2 * rec(pos + 2, s, dp);
                else 
                    ret += rec(pos+2, s, dp);
            }
        }
        ret %= mod;
        return ret;
    }
};
    
int main() {
    Solution sol;

    assert(sol.numDecodings("**")==96);
    assert(sol.numDecodings("1*")==18);
    assert(sol.numDecodings("2*")==15);
    assert(sol.numDecodings("*2")==11);
    assert(sol.numDecodings("*2")==11);
    printf("%d\n", sol.numDecodings("204"));
    assert(sol.numDecodings("*1*1*0")==404);
}