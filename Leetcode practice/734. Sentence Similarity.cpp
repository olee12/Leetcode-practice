#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size()) return false;
        unordered_map< string, set<string> > dict;

        for(auto &it: pairs){
            dict[it.first].insert(it.second);
            dict[it.second].insert(it.first);
        }

        for(int i = 0; i<words1.size();i++){
            string &a = words1[i];
            string &b = words2[i];
            if( a!=b && dict[a].find(b)==dict[a].end()){
                return false;
            }
        }
        return true;
    }
};


int main()
{

    return 0;
}