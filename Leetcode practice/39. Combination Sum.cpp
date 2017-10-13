#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        
        vector< vector<int> > ret;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
         helperCombinationSum(0,candidates,target,combination,ret);
         return ret;

    }
    
    void helperCombinationSum(int pos,vector<int> &candidates, int target, vector<int> &combination, vector< vector<int> > &ret ){
        if(pos == candidates.size()){
            if(target==0){
                ret.push_back(combination);
            }
            return ;
        }
        if(target < 0) return ;

        combination.push_back(candidates[pos]);
        helperCombinationSum(pos,candidates,target-candidates[pos],combination,ret);
        combination.pop_back();
        helperCombinationSum(pos+1,candidates,target,combination,ret);
    }

};


int main(){


}