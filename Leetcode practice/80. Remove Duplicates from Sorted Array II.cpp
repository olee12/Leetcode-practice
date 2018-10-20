#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //olee12
        if(nums.size()==0) return 0;
        int cur = nums[0];
        int cnt = 1;
        int indx = 1;


        for(int i = 1;i<nums.size();i++){
            if(cur == nums[i] && cnt <2){
                nums[indx++] = nums[i];
                cnt++;
            }else if(cur == nums[i]){
                cnt++;
            }else{
                cur = nums[i];
                nums[indx++] = nums[i];
                cnt = 1; 
            }
        }
        return indx;
    }
};



int main(){

    return 0;
}