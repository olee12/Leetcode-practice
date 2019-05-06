#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> arr;
        // printf("size %d\n",arr.size());
        int cumulative = 0;
        for(auto val : nums){
            cumulative+=val;
            arr.push_back(cumulative);
            printf("%d ",cumulative);
        }
        printf("\n");

        int x,y;
        int len = numeric_limits<int>::max();
        for(int i = 0;i<arr.size();i++){
            int next =  s;
            if(i>0) next = arr[i-1] + s;
            vector<int>::iterator it = lower_bound(arr.begin()+i,arr.end(),next);
            if(it == arr.end() || *it<next) continue;
            int sub = it - (arr.begin() + i) + 1;
            // printf("i = %d, arr[i] = %d, next = %d, sub = %d\n",i,arr[i],next,sub);
            if (sub < len) {
                len = sub;
            }
        }
        if(len == numeric_limits<int>::max()) return 0;
        return len;
    }
};




int main() {
    vector<int> nums = {1,2,3,4,5};
    Solution sol;
   printf("ret = %d\n", sol.minSubArrayLen(11,nums));
}