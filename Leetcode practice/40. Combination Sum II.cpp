#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        vector<vector<int>> ret;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        helperCombinationSum(0, candidates, target, combination, ret);
        return ret;
    }

    void helperCombinationSum(int pos, vector<int> &candidates, int target, vector<int> &combination, vector<vector<int>> &ret)
    {

        if (target == 0)
        {
            ret.push_back(combination);
            return ;
        }
        

        if (target < 0)
            return;
        
        for(int i = pos;i<candidates.size();i++){
            if(i==pos || candidates[i] != candidates[i-1]){
                combination.push_back(candidates[i]);
                helperCombinationSum(i+1,candidates,target-candidates[i],combination,ret);
                combination.pop_back();
            }
        }
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(5);
    int target = 8;
    Solution *sol = new Solution;
    vector< vector<int> > ret = sol->combinationSum2(vec,target);

    for(auto it = ret.begin();it != ret.end();it++){
        for(auto i = (*it).begin();i!= (*it).end();i++){
            printf("%d, ",*i);
        }
        printf("\n");
    }

}