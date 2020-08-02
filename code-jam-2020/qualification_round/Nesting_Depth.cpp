#include<bits/stdc++.h>
using namespace std;


struct Solution {
    string GetSolution(string s) {
       str = s;
       string tmp; 
       rec(0,0, tmp);
       return tmp; 
    }
    private:
    string str;
    void rec(int pos,int open, string &tmp) {
        if(pos == str.size()) {
            for(int i = 0;i<open;i++) tmp.push_back(')');
            return;
        }
        int val = str[pos] - '0';
        int n = abs(val-open);
        char ch;
        if(val > open){
            // open more
            ch = '(';
            open+=n;   
        }else if(val < open){
            // close 
            ch = ')';
            open-=n;
        }
        for(int i = 0;i<n;i++) tmp.push_back(ch);
        tmp.push_back(str[pos]);
        rec(pos+1, open, tmp);
    } 
};

string getValidString(int pos) {}

int main() {
    ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    int test;
    int cas = 1;
    cin>>test;
    while(test--) {
        string str;
        cin >> str;
        Solution *sol = new Solution();

        cout <<"Case #"<<cas++<<": "<< sol->GetSolution(str)<<"\n";
        delete sol;
    }
    return 0;

}