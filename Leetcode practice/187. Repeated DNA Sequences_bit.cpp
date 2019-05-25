#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>
using namespace std;

void printBit(long long val) {
    for(int i=0;i<40;i++){
        if(val & (1ll<<i)){
            cout<<'1';
        }else {
            cout<<'0';
        }
    }
    cout<<endl;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) {
        vector<string> ret;
        long long mask = 0;
        int m = 10;
        unordered_map<char,long long> dict;
        dict['A'] = 0x0;
        dict['T'] = 0x1;
        dict['G'] = 0x2;
        dict['C'] = 0x3;
        bitset<1<<20> one;
        bitset<1<<20> two;
        int ofset = 2;
        for(int i = 0;i<m;i++){
            long long tmp = dict[str[i]] << (ofset*i);
            mask |= tmp;
        }
        one[mask] = 1;
        for(int i = 1;i+m-1<str.size();i++){
            mask = mask >> ofset;
            mask |= (dict[str[i+m-1]] << (ofset*(m-1)));            
            if(one[mask]){
                if(two[mask]) continue;
                two[mask]=1;
                ret.push_back(str.substr(i,m));
            }
            one[mask] = 1;
        }
        return ret;
    }
};


int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution sol;
    vector<string> ret = sol.findRepeatedDnaSequences(s);
    for(string str : ret) {
        cout<<str<<endl;
    }
}