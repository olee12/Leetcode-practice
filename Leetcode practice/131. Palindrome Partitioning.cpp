#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    bool is_palindrom(string s,int i,int j)
    {
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void bt(int start,string s,vector<string> &tmp,vector< vector<string> > &ret)
    {
        if(start >= s.size()){
            ret.push_back(tmp);
            return ;
        }

        for(int i = start;i<s.size();i++){
            if(is_palindrom(s,start,i)){
                tmp.push_back(s.substr(start,i - start + 1));
                bt(i+1,s,tmp,ret);
                tmp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector< vector<string> > ret;
        vector< string > tmp;

        bt(0,s,tmp,ret);
        return ret;
    }
};

int main()
{

}