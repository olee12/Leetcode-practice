#include <bits/stdc++.h>
using namespace std;
#define oo (1<<29)

int dp[1<<15];
vector<string> stickers;
string target;
int len;
int rec(int mask){
    if(mask == ((1<<len) -1)){
        return 0;
    }
    int &ret = dp[mask];
    if(ret!=-1) return ret;
    ret = oo;

    for(string &sticker: stickers){
        int now = mask;
        for(char ch: sticker){
            for(int i = 0;i<len;i++){
                if(now & (1<<i)) continue;
                if(ch==target[i]){
                    now|=(1<<i);
                    break;
                }
            }
        }
        ret = min(rec(now) + 1, ret);
    }
    return ret;
}


class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        ::target = target;
        ::stickers = stickers;
        ::len = target.size();
        memset(dp,-1,sizeof(dp));
        int ret = rec(0);
        if(ret>=oo) return -1;
        return ret;

    }
};

int main(){
    vector<string> str;
    str.push_back("with");
    str.push_back("example");
    str.push_back("science");
    string target = "basicbasic";
    Solution sol;
    int ret = sol.minStickers(str,target);
    printf("Result : %d\n",ret);
}