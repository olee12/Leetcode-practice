#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp = vector<int> (nums.size(), 0);
        vector<int> nnums = vector<int>(nums.size(), 0);
        for(int i = 0;i<nums.size();i++) nnums[i] = nums[i];
        return mergeSort(0, nums.size() - 1, nnums, tmp);
    }
    int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp) {
        if(r <= l) return 0;
        int m = (l + r) / 2;
        int x = mergeSort(l, m, nums, tmp);
        int y = mergeSort(m + 1, r, nums, tmp);
        return x + y + merge(l, r, nums, tmp);
    }

    int merge(int low, int high, vector<int> &nums, vector<int> &tmp) {
        int mid = (low + high) / 2;
        int left = mid + 1;
        int count = 0;
        int k = mid + 1;
        int idx = 0;

        for(int i = low;i<=mid;i++) {
            while(left <= high && (long long)nums[i] > 2ll* (long long) nums[left]) left++;
            count += (left - (mid + 1));
            while(k <= high && nums[i] >= nums[k]) tmp[idx++] = nums[k++];
            tmp[idx++] = nums[i];
        }

        while(k <= high) tmp[idx++] = nums[k++];
        for(int i = low, idx = 0;i<=high;i++, idx++) nums[i] = tmp[idx];
        return count;
    }
};


int main(int argc, char const *argv[])
{

        Solution sol;

    vector<int> arr = {2,4,3,5,1};
    cout <<"\n\n----"<< sol.reversePairs(arr)<<endl;
    assert(sol.reversePairs(arr) == 3);

    /* code */
    return 0;
}
