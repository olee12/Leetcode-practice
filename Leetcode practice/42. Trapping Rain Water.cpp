#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int len = height.size();
        int *prefix = new int[len];
        int *suffix = new int[len];

        prefix[0] = height[0];
        suffix[len-1] = height[len-1];
        int end = len-2;
        for(int i = 1;i<len-1;i++,end--){
            prefix[i] = max(prefix[i-1],height[i]);
            suffix[end] = max(suffix[end+1],height[end]);
        }
        int area = 0;
        for(int i = 1;i<len-1;i++){
            int left = prefix[i-1];
            int right = suffix[i+1];
            int mn = min(left,right);
            if(height[i]<mn){
                area+= mn-height[i];
            }
        }
        return area;
    }
};

int main(){
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(arr,arr+sizeof(arr)/sizeof(arr[0]));

    Solution *sol = new Solution;
    printf("area :  %d\n",sol->trap(height));


}