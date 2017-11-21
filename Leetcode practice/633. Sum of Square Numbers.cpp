#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(long long c) {
        for(long long a = 0; a*a <= c;a++){
            double b = sqrt(c - a*a);
            if( b==(long long) b)
                return true;
        }
        return false;
    }
};

int main()
{

}