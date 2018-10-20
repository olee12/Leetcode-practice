#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
// olee12
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> dict;
        for(auto word:wordDict) dict[word] = true;
        dp.clear();
        visite = vector<bool> (s.size()+1,false);
        return rec(s,dict,0);
    }
    
    vector<string>& rec(string &s,unordered_map<string,bool>& wordDict,int pos) {
        if(visite[pos]) return dp[pos];
        if(pos >= s.size()){
            visite[pos] = true;
             dp[pos].push_back("");
             return dp[pos];
         }
        vector<string>& ret = dp[pos];
        
        for(int i = pos;i<s.size();i++){
            string cur = s.substr(pos,i - pos + 1);
            if(wordDict[cur]){
                vector<string>& sentances = rec(s,wordDict,i+1);

                for(auto part : sentances){
                    ret.push_back(cur + (part==""?"": " ") + part );
                }
            }
        }

        //cout<<"pos : "<<pos<<" vecsize: "<<dp[pos].size()<<endl;
        visite[pos] = true;
        return dp[pos];
    }

private:
    unordered_map<int,vector<string> > dp;
    vector<bool> visite;

};
int main()
{

    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // cout<<s.size()<<endl;
    // return 0;
    vector<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    Solution sol;
    vector<string> ret = sol.wordBreak(s,dict);
    for(auto it : ret){
        cout<<it<<endl;
    }
    return 0;
}