#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string rom[] = {"","I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};    
    	int inte[] = {0,1,4,5,9,10,40,50,90,100,400,500,900,1000};

    	string roman = "";
    	for(int i = 13;i>=1;i--){
    		int t = num/inte[i];
    		string ss = "";
    		while(t--){
    			ss+=rom[i];
    		}
    		roman = roman + ss; 
    		num = num % inte[i];
    	}
    	return roman;
    }
};

int main()
{
	freopen("inp.txt","r",stdin);
	int n;
		while(cin>>n){
		Solution ret;
		printf("%s\n", ret.intToRoman(n).c_str());
	}
}