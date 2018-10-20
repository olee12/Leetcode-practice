#include <iostream>
#include <string>
#include <map>
using namespace std;
//ab
//aa
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> dict;
        map<char,char> rdict;
        for(int i = 0;i<s.size();i++){
            
             if(dict.find(s[i])==dict.end() && rdict.find(t[i])==rdict.end()){
                dict[s[i]] = t[i];
                rdict[t[i]] = s[i];
            }
            else if(dict[s[i]]!=t[i]) return false;
        }
        return true;
    }
};

int main()
{
    return 0;

}
