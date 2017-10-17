#include <bits/stdc++.h>
using namespace std;


vector<int> arr;
void rec(int mask,vector<int> &permutation,vector< vector<int> > &ret){
    if(permutation.size()==arr.size()){
        ret.push_back(permutation);
        return ;
    }
    int pos = permutation.size();

    for(int i = 0;i<arr.size();i++){
        if(mask & (1<<i)) continue;

        permutation.push_back(arr[i]);

        if(i>0 && arr[i-1]==arr[i]){
            if(mask & (1<<(i-1)))
                rec(mask | (1<<i),permutation,ret);
        }else{
            rec(mask | (1<<i),permutation,ret);
        }
        permutation.pop_back();
    }
    return ;
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ::arr = nums;
        vector<int> permutation;
        vector< vector<int> > ret;
        rec(0,permutation,ret);
        return ret;
    }
};


int main(){
    Solution sol;
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(1);
    
    vector< vector<int> > ret;
printf("SOLUTION : \n");
    ret = sol.permuteUnique(vec);
    

    for(auto it = ret.begin();it != ret.end();it++){
        
        for(auto i = (*it).begin();i!= (*it).end();i++){
            printf("%d ",*i);
        }
        printf("\n");

    }
}