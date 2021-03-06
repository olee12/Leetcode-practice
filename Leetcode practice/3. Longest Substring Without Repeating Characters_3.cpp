#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> freq;
        int left = 0;
        int right = 0;
        int ret = 0;

        for(;right < s.size() && left < right;right++) {
            freq[s[right]]++;
            bool okay = verify(freq);
            while(okay == false) {
                freq.erase(s[left]);
                okay = verify(freq);
            }
            if(okay) {
                if( right - left + 1 > ret){
                    ret = right - left + 1;
                }
            }
        }
        return ret;
    }
    bool verify(map<char, int> &freq) {
        for(auto &it:freq) if (it.second > 1) return false;
        return true;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
