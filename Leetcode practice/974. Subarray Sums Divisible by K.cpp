#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> mod(K, 0);
        int sum = 0;
        for(int i = 0;i<A.size();i++) {
            sum+= A[i];
            mod[((sum % K) + K) % K ]++;
        }
        int ret = 0;
        for(int i = 0;i < K; i++) {
            if(mod[i] > 1) {
                ret += ((mod[i] * (mod[i] - 1)) / 2);
            }
        }
        ret += mod[0];
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}



