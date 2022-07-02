#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int palindromLen(int mask, string &s) {
        int i = 0;
        int j = s.size() - 1;
        int ret = 0;
        while(i <= j) {
            if((mask & (1 << i))==0) i++;
            else if((mask & (1 << j))==0) j--;
            else if(s[i] != s[j]) return 0;
            else ret += 1 + (i++ != j--);

        }
        return ret;  
    }
    
    int maxProduct(string s) {
       int limit = (1 << s.size())  - 1;
      // cout << limit << endl;
       int dp[limit + 1];
       memset(dp, 0, sizeof dp);
       for(int i = 0;i<=limit;i++){
           dp[i] = palindromLen(i, s);
       } 

        int ret = 0;
        for(int j = 0;j<=limit;j++) {
            int x = (j ^ limit) ;
            for(int i = x ; i>0; i = (i - 1) & x) {
                ret = max(ret, dp[i] * dp[j]);
               // cout << j << ' '<< i << ' ' << dp[i] << ' ' << dp[j] << endl;
                // ret = max(ret, dp[i ^ limit] * dp[j]);
            }
         //   cout << endl;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout <<sol.maxProduct("uui")<<endl;;
    /* code */
    return 0;
}
