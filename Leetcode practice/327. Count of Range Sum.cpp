#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<long long> sum;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
         sum = vector<long long>(nums.size()+1, 0);
        // -2, 5, -1
    // 0, -2, 3, 2
        for(int i = 0;i<nums.size();i++) sum[i + 1] = sum[i] + nums[i];

        // for(int i = 0;i<=sum.size() - 1;i++) printf(" %d", sum[i]);
        // printf("--\n");

        return mergeSort(0, sum.size() - 1, lower, upper);
    }

    int mergeSort(int low, int high, long long lower, long long upper) {
        if (high <= low ) return 0;
        int mid = (low + high) / 2;
        int x = mergeSort(low, mid, lower, upper);
        int y = mergeSort(mid + 1, high, lower, upper);
        return x + y + merge(low, high, lower, upper);

    }

    int merge(int low, int high, long long lower, long long upper) {
        int mid = (low + high) / 2;
        int l = mid + 1;
        int r = mid + 1;
        int k = mid + 1;
        int idx = 0;
        vector<long long> tmp(high - low + 1, 0);
        // printf("low: %d, high: %d, tmp.size(): %d\n", low, high, tmp.size());
        int count = 0;
        for(int i = low;i<=mid;i++) {

            while(l <= high && sum[l] - sum[i] < lower ) l++;
            while(r <= high && sum[r] - sum[i] <= upper) r++;

            count += (r - l);

            while(k <= high && sum[k] < sum[i]) tmp[idx++] = sum[k++];
            tmp[idx++] = sum[i]; 
        }
        while(k <= high) tmp[idx++] = sum[k++];
        idx = 0;
        for(int i = low; i<=high;i++)  sum[i] = tmp[idx++];

        // printf("tmp: ");
        // for(auto i:tmp) printf(" %d", i);
        // printf("\n");
        // printf("low: %d, high: %d, count: %d\n", low, high, count);
        // printf("sum: ");
        // for(int i = low;i<=high;i++) printf(" %d", sum[i]);
        // printf("\n");
        return count;
    }
};


int main(int argc, char const *argv[])
{
    
    vector<int> inp = {-2, 1, 1};
    Solution sol;
    cout << sol.countRangeSum(inp, -2, 2)<<endl;;
    return 0;
}
