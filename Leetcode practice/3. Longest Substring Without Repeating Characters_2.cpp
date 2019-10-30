#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int low = 0;
        int len = 1;
        map<char, int> dict;
        for(int high = 0;high<s.size();high++) {
                if(dict.find(s[high]) != dict.end()) {
                    low = max(low, dict[s[high]] + 1);
                }
                len = max(len, high - low + 1);
                dict[s[high]] = high;
        }
        return len;
    }
};

int main() {
    string str = "au";
    Solution sol;
    cout<<sol.lengthOfLongestSubstring(str)<<endl;
}