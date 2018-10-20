#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> dict;
        vector<vector<char>> vec(s.size()+1,vector<char>());
        for(char ch:s){
            dict[ch]++;
        }
        for(auto it:dict){
            vec[it.second].push_back(it.first);
        }
        string ret = "";
        for(int i = s.length();i>=1;i--){
            if(vec[i].size())
                for(char ch:vec[i])
                    for(int cnt = 0;cnt<dict[ch];cnt++) ret.push_back(ch);
        }
        return ret;
    }
};


int main()
{
    string str = "Aabb";
    Solution sol;
    cout<<sol.frequencySort(str)<<endl;

    return 0;
}