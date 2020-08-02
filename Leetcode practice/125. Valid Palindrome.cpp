#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size();
        while (i < j)
        {
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            } 
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;j--;
        }
        return true;     
    }
};

int main() {
    Solution sol;
    cout<< sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car")<< endl;
}