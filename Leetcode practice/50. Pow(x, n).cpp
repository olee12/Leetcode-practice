#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n == numeric_limits<int>::min()){
            x = x * x;
            n/=2;
        }    
        if(n<0){
            x = 1./x;
            n = -n;
        }
        double ret = myPow(x,n/2);
        ret = ret * ret;
        if(n&1) ret = ret * x;
        return ret;
    }
};


int main()
{
    Solution sol;

    cout<<sol.myPow(5,numeric_limits<int>::min())<<endl;
    cout<<sol.myPow(2,10)<<endl;
    cout<<sol.myPow(2.10000,3)<<endl;

}