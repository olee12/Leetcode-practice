#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;




class Solution {
public:
    string find_par(unordered_map<string,string> &par,string r){
        if(par[r]==r){
            return r;
        }
       return par[r] = find_par(par,par[r]);
    }


    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string> > pairs) {
        if(words1.size()!=words2.size()){
            return false;
        }
        unordered_map<string,string> par;
        for(auto it : pairs){
            par[it.first] = it.first;
            par[it.second] = it.second;
        }
        
        for(auto it : pairs){
            //cout<<it.first<<" : "<<it.second<<endl;
            string a = find_par(par,it.first);
            string b = find_par(par,it.second);
            if(a!=b){
                par[a] = b;
            }
            //cout<<" key : "<<a<<" : "<<par[a]<<endl;
        }

        for(int i = 0; i<words1.size();i++){
            string a = find_par(par,words1[i]);
            string b = find_par(par,words2[i]);
            //cout<<a<<" : "<<b<<" : "<<words1[i]<<" : "<<words2[i]<<endl;
            if(a!=b){
                return false;
            }
        }
        return true;

    }
};


int main()
{

}