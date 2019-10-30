#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string str, string t) {
        unordered_map<char,int> dict;
        unordered_map<char,int> freq;
        for(char ch:t) freq[ch]++;
        int s = 0, p = 0;
        int ans = str.size() + 1;
        int i = 0,j = 0;
        for(;j<str.size();j++) {
            dict[str[j]]++;
            // printf("%d %d ",j,dict.size());printKV(dict);
            while(i < str.size() && check(dict, freq)) {
                if (ans > j - i) {
                    s = i;
                    p = j;
                    ans = j - i;
                }
                // printf("i,j %d %d\n",i,j);
                dict[str[i]]--;
                i++;
            }
        }
        // printf("final: %d %d\n",s,p);
        if(ans == str.size() + 1) return "";
        return str.substr(s, p - s + 1);
    }
    bool check(unordered_map<char,int> &dict, unordered_map<char,int> &freq) {
        for(auto it:freq) {
            if(dict[it.first]< it.second) return false;
        }
        return true;
    }
    void printKV(unordered_map<char,int> &dict) {
        for(auto &it : dict) printf(" [%c %d]",it.first, it.second);
        printf("\n");
    }
};

int main() {
    string str = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    cout << "ans : "<<sol.minWindow(str,t)<<endl;
}