#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int bit[100005];


void update(int idx, int value, int n) {
    while(idx <= n) {
        bit[idx] += value;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while(idx>0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
       set<int> st;
       unordered_map<int,int> dict;

       for(auto &n:nums) st.insert(n);
       int idx = 1;
       for(auto &n:st) dict[n] = idx++;


        vector<int> ret = vector<int>(nums.size(), 0);
        for(int i = nums.size() - 1;i>=0;i--) {
            int &num = nums[i];
            int l = dict[num];
            ret[i] = query(l-1);
            update(dict[num], 1, st.size());
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Solution sol;
    vector<int> inp = {-1, -2};
    printf("result: ");
    for(auto &it:sol.countSmaller(inp)) printf("%d ", it);
    printf("\n");
    return 0;
}


