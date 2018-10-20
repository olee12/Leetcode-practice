#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int rec(vector< vector<int> > &dp,int i,int j,string &str1,string &str2){
        
        if(i==-1 || j==-1){
            return max(i+1,j+1);
        }

        int &ret = dp[i][j];
        if(ret != -1) return ret;
        ret = numeric_limits<int>::max();

        if(str1[i]==str2[j])
            return ret = min(ret,rec(dp,i-1,j-1,str1,str2));

        ret = min(ret,rec(dp,i-1,j-1,str1,str2)+1);
        ret = min(ret,rec(dp,i-1,j,str1,str2)+1);
        ret = min(ret,rec(dp,i,j-1,str1,str2)+1);
        return ret;
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector< vector<int> > dp(n,vector<int>(m,-1));

        return rec(dp,n-1,m-1,word1,word2);
    }
};


int main()
{
    string a,b;
    while(cin>>a>>b){
        Solution sol;
        cout<<"edit Distance: "<<sol.minDistance(a,b)<<endl;
    }

}
/**
dinitrophenylhydrazine
benzalphenylhydrazone

*/