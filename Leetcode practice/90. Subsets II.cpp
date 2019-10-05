#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int> > ret;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ret = vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<int> bag;
        rec2(0, bag, nums);
        return ret;
    }
    void rec(int pos, vector<int> &bag, vector<int> &nums){
        // printf("%d %d %d\n",pos, bag.size(), nums.size());
        if (pos == nums.size()) {
            vector<int> tmp;
            for( int &i : bag) {
                // printf("i %d\n",i);
                tmp.push_back(nums[i]);
            }
            // printf("\n");
            ret.push_back(tmp);
            return ;
        }
        
        rec(pos + 1, bag, nums);
        if(pos > 0 && nums[pos-1]==nums[pos]) {
            if ( bag.size() && bag.back() != pos -1) return;
            else if (bag.size()==0) return;
        }
        bag.push_back(pos);
        rec(pos+1, bag, nums);
        bag.pop_back();
    }
    void rec2(int pos, vector<int> &bag, vector<int> &nums){
        ret.push_back(bag);
        for(int i = pos;i<nums.size();i++) {
            if (i == pos || nums[i] != nums[i-1]) {
                bag.push_back(nums[i]);
                rec2(i+1,bag,nums);
                bag.pop_back();
            }
        }        
    }
};



int main() {
    vector<int> vec = {1,2,2};
    Solution sol;
    vector< vector<int> > ret;

    ret = sol.subsetsWithDup(vec);
    printf("len of ret= %d\n",ret.size());
    for (auto &r : ret) {
        for (int &v : r) {
            printf("%d ", v);
        }
        printf("\n");
    }
}