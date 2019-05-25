#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

long long getHash(string &str,int m, long long B, long long M) {
    long long power = 1;
    long long ret = 0;
    for(int i = m - 1;i >= 0;i--){
        ret = ret + (str[i] * power) % M;
        ret %= M;
        power = (power * B) % M; 
    }
    return ret;
}

vector<string> rollingHash(string &str, int m, long long B1, long long M1,long long B2, long long M2) {
    vector<string> ret;
    if (str.size() < m) {
        return ret;
    }

    long long power1 = 1;
    long long power2 = 1;
    for(int i = 0;i<m-1;i++){
        power1 = (power1*B1)%M1;
        power2 = (power2*B2)%M2;
    }

    map<long long,int> dict1;
    map<long long,int> dict2;
    long long hash1 = getHash(str,m,B1,M1);
    long long hash2 = getHash(str,m,B2,M2);
    dict1[hash1] = 1;
    dict2[hash2] = 1;

    for(int i = 1;i+m-1<str.size();i++){
        hash1 = (hash1 - str[i-1]*power1) % M1;
        hash1 = (M1 + hash1) % M1;
        hash1 = (hash1 * B1) % M1;
        hash1 = (hash1 + str[i+m-1]) % M1;
        dict1[hash1]++;

        hash2 = (hash2 - str[i-1]*power2) % M2;
        hash2 = (M2 + hash2) % M2;
        hash2 = (hash2 * B2) % M2;
        hash2 = (hash2 + str[i+m-1]) % M2;
        dict2[hash2]++;

        if(dict1[hash1]==2 && dict2[hash2]==2){
            ret.push_back(str.substr(i,m));
        }
    }
    return ret;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const long long M1 = 1000000000 + 7;
        long long B1 = 997;
        const long long M2 = 1000000000 + 7;
        long long B2 = 9973;
        return rollingHash(s,10,B1,M1,B2,M2);
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