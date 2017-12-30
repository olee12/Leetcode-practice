#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
    void reverse(vector<int>&nums,int beg,int end)
    {
        while(beg < end){
            swap(nums[beg],nums[end]);
            beg++;
            end--;
        }
    }
};


int main()
{
    int n;
    int k;
    while(scanf("%d %d",&n,&k)==2){
        vector<int> vec;
        for(int i = 1;i<=n;i++){
            vec.push_back(i);
        }
        Solution sol;
        sol.rotate(vec,k);

        for(int &a:vec){
            printf("%d ",a);
        }
        printf("\n\n");

    }

}