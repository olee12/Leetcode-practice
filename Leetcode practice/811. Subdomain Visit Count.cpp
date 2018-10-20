#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //olee12
    void split(string &str,vector<string> &vec,char delim = ' '){
        istringstream ss(str);
        string token;
        while(getline(ss,token,delim)) vec.push_back(token);
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> dict;

        for(string cpdomain:cpdomains){
            vector<string> tokens;
            split(cpdomain,tokens,' ');
            string &str_cnt = tokens[0];
            string &domain = tokens[1];
            int cnt = stoi(str_cnt);
            
            int current, previous = 0;
            current = domain.find('.');
            while(current!=string::npos){
                string go = domain.substr(previous);
                dict[go]+=cnt;
                previous = current + 1;
                current = domain.find('.',previous);

            }
            string go = domain.substr(previous);
            dict[go]+=cnt;
        }
        vector<string> olee;
        for(auto it : dict){
            string ret = to_string(it.second) + " " + it.first;
            olee.push_back(ret);
        }
         
         return olee;

    }
};

int main()
{
    string go = "100 olee.google.com";
    vector<string> vec(1,go);
    Solution sol;
    vec = sol.subdomainVisits(vec);
    for(string s:vec) cout<<s<<endl;

}