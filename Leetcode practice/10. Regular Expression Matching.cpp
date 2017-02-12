#include <bits/stdc++.h>
using namespace std;


string s,p;


bool match(int i,int j)
{
	return s[i]==p[j] || (p[j]=='.' && s[i]!='\0');
}

int rec(int i,int j)
{
	if(p[j]=='\0') return s[i]=='\0';

	if(p[j+1]=='*'){
		if(rec(i,j+2)) return true;
		while(match(i,j)) if(rec(++i,j+2)) return true;
	}else {
		if(match(i,j)==false) return false;
		return rec(i+1,j+1);
	}
	return 0;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        ::s = s;
        ::s+='\0';
        ::p = p;
        ::p+='\0';
        return rec(0,0);
    }
};

int main()
{
	Solution a;
	printf("%d\n",a.isMatch("aab","c*a*b") );

}