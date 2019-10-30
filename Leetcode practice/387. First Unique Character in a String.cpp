#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int,int> > dict;
        for(int i = 0;i<s.size();i++) {
            dict[s[i]].first++;
            dict[s[i]].second = i;
        }
        int ret = s.size();
        for(auto &it:dict) {
            if (it.second.first == 1) {
                ret = min(it.second.second,ret);
            }
        }
        return s.size()==ret?-1:ret;
    }
};


int main() {

}