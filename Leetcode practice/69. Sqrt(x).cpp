#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;

        int cnt = 70;
        double esp = 1e-9;
        double low = 0;
        double high = numeric_limits<int>::max();

        while(cnt--){
            double mid = (low + high) / 2;

            if(mid * mid < x){
                low = mid + esp;
            }
            else high = mid - esp;
        }
        return floor(low);
    }
};



int main()
{
      Solution sol;

    cout<<sol.mySqrt(numeric_limits<int>::max())<<endl;
    cout<<sol.mySqrt(8)<<endl;
    cout<<sol.mySqrt(2)<<endl;
}