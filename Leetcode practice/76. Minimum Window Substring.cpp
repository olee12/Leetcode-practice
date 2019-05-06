#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <limits>
using namespace std;



class Solution {
public:
    string minWindow(string str, string t) {
        if(t=="" || str == "") return "";

        set<int> visited;
        
        vector<int> nextPos(str.size(),-1);
        // cout<<"step 1"<<endl;
        unordered_map<char,int> dictPos;
        unordered_map<char,int> tFreq;
        
        for(int i = str.size() - 1; i >= 0; i--) {
            if(dictPos.count(str[i])) {
                nextPos[i] = dictPos[str[i]];
            }else {
                nextPos[i] = -1;
            }
            dictPos[str[i]] = i;
        }

        for(char &ch:t) {
            tFreq[ch]++;
        }

        unordered_map<char,int> taken;        

        int start;
        int end;
        int minLen = numeric_limits<int>::max();
        dictPos.clear();
        // cout<<"olee"<<endl;
        for(int i = 0;i<str.size();i++) {
            
            if(taken.size() && check(tFreq,taken)) {
                int len = *(visited.rbegin()) - *(visited.begin()) + 1;
                // cout<<"lenL: "<<len<<endl;
                // for(auto &a : visited){
                //     cout<<a<<' ';
                // }
                // cout<<endl;
                if (len < minLen){
                    minLen = len;
                    start = *(visited.begin());
                    end = *(visited.rbegin());
                }
            }

            char &ch = str[i];

            if( dictPos.find(ch) == dictPos.end() ){
                dictPos[ch] = i;
            }

            taken[ch]++;
            if(tFreq[ch]) visited.insert(i);
            if(tFreq[ch] && tFreq[ch] < taken[ch]) {
                if(visited.size()) visited.erase(dictPos[ch]);
                dictPos[ch] = nextPos[dictPos[ch]];
                taken[ch]--;
                visited.insert(dictPos[ch]);
                // cout<<i<<' '<<ch<<' '<<dictPos[ch]<<endl;

            }
        }
        if(taken.size() && check(tFreq,taken)) {
            int len = *(visited.rbegin()) - *(visited.begin()) + 1;
            // cout<<"lenL: "<<len<<endl;
            // for(auto &a : visited){
            //     cout<<a<<' ';
            // }
            // cout<<endl;
            if (len < minLen){
                minLen = len;
                start = *(visited.begin());
                end = *(visited.rbegin());
            }
        } else {
            return "";
            /* code */
        }
        
        
        return str.substr(start,minLen);
    }

    bool check(unordered_map<char,int> &tFreq, unordered_map<char,int> &sFreq) {
        for(auto &it : tFreq) {
            if(sFreq[it.first] < it.second) return false;
        }
        return true;
    }

};


int main() {
    string s = "ADOBECODEBANCOLEE";
    string t = "CELE";
    Solution sol;
    cout<<"Ans: "<<sol.minWindow(s,t)<<endl;
}

