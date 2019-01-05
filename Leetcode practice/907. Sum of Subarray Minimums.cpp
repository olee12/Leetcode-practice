#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    int sumSubarrayMins(vector<int>& ara) {
        int ret = 0;
        int n = ara.size();
        int mod = 1000000007;
        stack<int> st;
        for(int i = 0;i<=n;i++){
            while(st.size() && ara[st.top()] > (i==n?0:ara[i])){
                int j = st.top(); st.pop();
                int k = st.size()?st.top():-1;
                ret = (ret + ara[j]*(i - j) * (j - k)) % mod;
            }
            st.push(i);
        }
        return ret;
    }
};


int main()
{
    vector<int> vec = {3,3};
    printf("%d\n",(new Solution())->sumSubarrayMins(vec));
}