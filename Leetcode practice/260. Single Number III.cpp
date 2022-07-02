#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long mask = 0;
        for(auto n:nums) mask ^= n;
        long long diff = mask & (-mask);
        long long x = 0;
        for(auto n:nums) if(diff & n) x^=n;
        return {(int)x, (int)(x^mask)};
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> t1 = {1,2,1,3,2,5};
    Solution sol;
    for(auto it:sol.singleNumber(t1)) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
