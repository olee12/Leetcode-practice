#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int divide(int dividend,int divisor){
        int cnt=0;
        cnt += (dividend<0);
        cnt += (divisor<0);
        long long result = 0;
        long long sum =  abs((long long)dividend);
        long long d = abs((long long) divisor);
        for(int i = 31;i>=0;i--){
            if( (d<<i) <= sum){
                result |= (1ll<<i);
                sum -= (d<<i);
            }
        }
        if(result > ((1ll<<31)-1) && cnt != 1) return INT_MAX;
        if(cnt==1) result = ~(result) + 1;
        if(result > ((1ll<<31)-1)) return INT_MAX;
        return (int)result;
    }
};

int main(){
    int a = -2147483648;
    printf(" a = %d\n",a);
    Solution *solution = new Solution;
    printf("%d %d\n",solution->divide(-2147483648,-1),((int)-2147483648/-1));
    //cout<<solution->divide(-2147483648,-1)<<' '<<(-2147483648/-1)<<endl;
    return 0;
}