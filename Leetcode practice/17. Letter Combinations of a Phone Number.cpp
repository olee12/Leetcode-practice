#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
string digits;
int vis[10];
std::vector<string> res;
string ret;
string table[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void rec(int pos) {
	if(pos == digits.size()) {
		res.push_back(ret);
		return ;
	}
	int now = digits[pos] - '0';
	for(int i = 0;i < table[now].size();i++){
		ret.push_back(table[now][i]);
		rec(pos+1);
		ret.pop_back();
	}
	return ;
}



class Solution {
public:
    vector<string> letterCombinations(string digits) {
		::digits = digits;

		memset(vis,0,sizeof(vis));
		res.clear();
		if(digits.size()==0) return res;
		rec(0);
		return res;
    }
};


int main() {

	return 0;
}
