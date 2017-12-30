#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        int mid;
        while(low < high){
             mid = (low + high) / 2;
            if(nums[mid] > nums[high]){
                low = mid + 1; 
            }else if(nums[mid] < nums[high]){
                high = mid;
            }else high--;
        }
        return nums[low];

    }
};


int main()
{
    vector<int> vec;
    
    
    int n;
    while(scanf("%d",&n)==1){
        vec.clear();
        int a;
        while(n--){
            scanf("%d",&a);
            vec.push_back(a);
        }
        printf("----- %d ------\n",(new Solution)->findMin(vec));
    }
    
   
    
}