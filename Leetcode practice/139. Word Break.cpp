#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int *dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(),wordDict.end());
        dp = (int*)malloc(sizeof(int)*(s.size()+1));
        for(int i = 0;i<s.size()+1;i++) dp[i] = 0;

       // bool ret = rec(0,dp,s,wordDict);
       bool ret = btUp(s,wordDict,dp);
        delete dp;
        return ret;
    }
    bool btUp(string s,vector<string>& dict,int *dp){
        dp[0] = 1;

        for(int i = 1;i<=s.size();i++){
            for(int j = 0;j<i;j++){
                if(dp[j]){
                    string sub = s.substr(j,i-j);
                    auto it = find(dict.begin(),dict.end(),sub);
                    if(it==dict.end() || (*it) != sub) continue;
                   // cout<<i<<' '<<j<<' '<<sub<<endl;
                    dp[i] = 1;
                }
            }
        }
        return dp[s.size()];


    }
    bool rec(int pos,int *dp,string &s,vector<string>& wordDict){
        if(pos>= s.size()){
            return true;
        }
        int &ret = dp[pos];
        if(ret != -1) return ret;
        ret = false;
        for(int i = pos;i<s.size();i++){
            string sub = s.substr(pos,i - pos + 1);
            auto it = lower_bound(wordDict.begin(),wordDict.end(),sub);
            if(it == wordDict.end() || (*it)!=sub) continue;
            
            ret = ret | rec(i+1,dp,s,wordDict);
            //cout<<i<<' '<<sub<<' '<<ret<<endl;
        }
        //printf("pos : %d  ret : %d\n",pos,ret);
        return ret;
    }
};

int main()
{
    Solution sol;

    string word = "leetcode";
    vector<string> dict = {"leet", "code"};

    printf("%d\n",sol.wordBreak(word,dict));
}