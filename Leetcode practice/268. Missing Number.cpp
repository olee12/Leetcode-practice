#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int sum = 0;
        for(int &a:nums){
            sum+=a;
        }
        long long n = nums.size();
        return (int)(n*(n+1)/2 - sum);
    }
};

int main()
{

}