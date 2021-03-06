#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> weight;
    vector<int> values;
    vector<vector<int>> dp;
    int total;
    int lastStoneWeightII(vector<int>& stones) {
       int sum = 0;
       weight = vector<int>(stones.size(), 0);
       values = vector<int>(stones.size(), 0);

       for(int i = 0;i<stones.size();i++) {
           sum+=stones[i];
           weight[i] = (stones[i]);
           values[i] = (stones[i]);
       } 
       int capacity = sum / 2;
       total = sum;
       dp = vector<vector<int> >(stones.size()+1,vector<int>(capacity+1, -1));
       printf("---\n");
       cout<<"dp: "<< rec(0, capacity) << " sum: "<<sum<<endl;
       return sum - rec(0, capacity) - (sum - rec(0, capacity));
    }

    int rec(int pos, int amount) {
        if(pos >= weight.size()) {
            return (amount <  0) ? -1*total:0;
        }
        if(amount == 0) return 0;
        if(amount < 0) return -1*total;
        // printf("--pos: %d, amount: %d, sz: %d\n", pos, amount, weight.size());
        int &ret= dp[pos][amount];
        if (ret != -1) return ret;
        ret = 0;
        ret = max(ret, rec(pos+1, amount-weight[pos])+values[pos]);
        ret = max(ret, rec(pos+1, amount));
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> inp = {1,1, 1};
    cout << sol.lastStoneWeightII(inp)<<endl;
    
    return 0;
}
