#include <bits/stdc++.h>
using namespace std;


string s,p;


int match(int i,int j)
{
	return s[i]==p[j] || (p[j]=='?' && s[i]!='\0');
}

bool rec(int *dp,int i,int j)
{
	if(i>=s.size()) return 0;
	if(p[j]=='\0') return s[i]=='\0';
	int &ret = dp[i*p.size() + j];
	if(ret != -1) return ret;
	 ret = 0;
	int r1 = 0,r2 =0; 
	if(p[j]=='*'){
		int r1 = rec(dp,i,j+1);
		int r2 = rec(dp,i+1,j);
		return ret = r1|r2;
	}else {
		if(match(i,j)==false) return ret = 0;
		return ret = rec(dp,i+1,j+1);
	}
	
}

class Solution {
public:
    bool isMatch(string s, string p) {
        ::s = s;
        ::s+='\0';
        ::p = p;
		::p+='\0';
		int *dp = new int[::s.size() * ::p.size()];
		memset(dp,-1,sizeof(int) * ::s.size() * ::p.size());
        return rec(dp,0,0);
    }
};

int main()
{
	Solution a;

	printf("%d\n",a.isMatch("baaaaa","b*") );

}