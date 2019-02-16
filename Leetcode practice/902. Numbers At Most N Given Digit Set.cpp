#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

vector<int> digits;
vector<int> nums;
int dp[10][2];


int rec(int pos,int flag,int zero){
    if(pos == -1) return zero == 0;

    int &ret = dp[pos][zero];

    if( ret != -1 && flag) return ret;

    int result = 0;
    int end = 9;

    if(flag==0) end = nums[pos];

    if(zero) result = rec(pos-1,1,1);

    for(int i = 0;i<digits.size();i++){
        if(flag==0 && digits[i]>end) continue;
        result += rec(pos-1,flag || (digits[i] < end),0);
    } 
    if(flag) ret = result;

    return result;
}


class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        digits.clear();
        nums.clear();
        for(string &dig: D){
            digits.push_back(dig[0] - '0');
        }
        int num = N;
        while(num > 0){
            nums.push_back(num%10);
            num/=10;
        }
        memset(dp,-1,sizeof(dp));
        return rec(nums.size() - 1,0,1);
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"1","4","9",};
    cout<< "result: "<<sol.atMostNGivenDigitSet(vec,1000000000) << endl;    
}