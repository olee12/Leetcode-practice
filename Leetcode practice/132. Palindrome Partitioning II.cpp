#include <bits/stdc++.h>
using namespace std;


const int maxn = 2001;
int dp[maxn][maxn];
int dp2[maxn][maxn];

class Solution {
public:
    int minCut(string s) {
        memset(dp, -1, sizeof (dp));
        memset(dp2, -1, sizeof (dp2));
        // for(int i = 0;i<s.size();i++) rec(0, i, s);

        return rec(0, s.size()-1, s);
    }
    int rec(int i, int j, string &s) {
        if (i >=j || isPalen(i, j, s) == 0 ) return 0;

        int &ret = dp[i][j];
        if (ret != -1) {
            return ret;
        }

        ret = numeric_limits<int>::max();

        // if (s[i]==s[j]) ret = rec(i+1, j-1, s);
        // ret = min(ret, rec(i, j-1,s) + rec(i+1, j, s) + 1);

        for(int p = i; p <=j; p++) {
            if (isPalen(i, p, s)==0)
                ret = min(ret, rec(p+1, j, s) + 1);
            
        }
        return ret;
    }

    int isPalen(int i, int j, string &s) {
        if (i >= j) return 0;
        int &ret = dp2[i][j];
        if (ret != -1) return ret;
        if (s[i]==s[j]) return ret = isPalen(i+1, j-1, s);
        ret = s.size();
        return ret;
    }
};



int main(int argc, char const *argv[])
{
    string inp = "bb";

    // for(int i = 1;i<1980;i++) inp.push_back('a');

    Solution sol;
    cout << sol.minCut(inp)<<endl;
    return 0;
}
