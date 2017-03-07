#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& ara, int target) {
        std::vector<std::vector<int> > ret;
        sort( ara.begin(),ara.end() );
        int len = ara.size();
        for(int i = 0; i < len - 3 ;i++){
        	while(i > 0 && ara[i]==ara[i-1]) i++;
        	for(int j = i + 1;j < len - 2;j++){
        		while(j > i + 1 && ara[j]==ara[j-1]) j++;
        		int ntr = target - ara[i] - ara[j];
        		int lft = j + 1;
        		int rght = len - 1;
        		while(lft < rght){
        			int sum = ara[lft] + ara[rght];
        			if(sum > ntr) rght--;
        			else if(sum < ntr) lft ++;
        			else{
        				std::vector<int> tmp;
        				tmp.clear();
        				tmp.push_back(ara[i]);
        				tmp.push_back(ara[j]);
        				tmp.push_back(ara[lft]);
        				tmp.push_back(ara[rght]);
        				ret.push_back(tmp);
        				printf("%d %d %d %d\n",i,j,lft,rght );
        				while(lft < rght && ara[lft]==tmp[ 2 ]) lft++;
        				while(lft < rght && ara[rght]==tmp[ 3 ]) rght--;
        			}
        		}
        	}
        }
        return ret;


    }
};

int main()
{	
	Solution ret;
	std::vector<int> v;
	v.push_back(-3);
	v.push_back(-3);
	v.push_back(-2);
	v.push_back(-2);
	v.push_back(-2);
	v.push_back(0);
	v.push_back(0);
	v.push_back(4);

	vector< std::vector<int> > vet = ret.fourSum(v,-1);
	printf("%d\n",vet.size() );

}