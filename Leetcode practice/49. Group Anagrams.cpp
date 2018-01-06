#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string> > dict;
        for(string str:strs){
            string t = str;
            sort(t.begin(),t.end());
            dict[t].push_back(str);
        }
        vector<vector<string> > ret;
        for(auto &it : dict){
            ret.push_back(it.second);
        }      
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    sol.groupAnagrams(strs);
}