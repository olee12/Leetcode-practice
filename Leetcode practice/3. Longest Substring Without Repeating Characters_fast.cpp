#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> dict;
        int low = 0;
        int ret = 0;
        for(int i = 0;i<s.size();i++) {
            if(dict.count(s[i])) low = max(low, dict[s[i]]+1);
            dict[s[i]] = i; 
            ret = max(ret, i - low + 1);
        }
        return ret;
    }
};




int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
