#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        if(s.size()<2){
            return s;
        }
        
        for(int i = 0;i<s.size();i++){
            check(s,i,i,start,maxLen);
            check(s,i,i+1,start,maxLen);
        }
        //cout<<start<<' '<<maxLen<<endl;
        return s.substr(start,maxLen);
    }
    void check(string &s,int i,int j,int &start,int &maxLen){
            
            while(i>=0 && j < s.size()){
                if(s[i]==s[j]) {
                    i--;
                    j++;
                }
                else break;
            }
            
            if(maxLen < j - i - 1){
                start = i + 1;
                maxLen = j - i - 1;
            }
        }
};

int main()
{

}