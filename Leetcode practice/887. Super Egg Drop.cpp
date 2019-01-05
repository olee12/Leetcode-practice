#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 10001;
const int maxk = 101;
int dp[maxn][maxk];
class Solution {
public:
    int superEggDrop(int K, int N) {
        memset(dp,-1,sizeof(dp));
        return recBin(N,K);
    }
    int rec(int high,int k){
        if(k==1) return high;
        if(high==0) return 0;
        int &ret = dp[high][k];

        if(ret != -1) return ret;

        ret = numeric_limits<int>::max();

        for(int i = 1;i<=high;i++){
            ret = min(ret, max(rec(i-1,k-1) , rec(high - i,k)  ) + 1);
        }
        return ret;
    }
    int recBin(int high,int k){
        if(k==1) return high;
        if(high==0) return 0;
        int &ret = dp[high][k];

        if(ret != -1) return ret;

        ret = numeric_limits<int>::max();

        int lo = 1;
        int hi = high;
        
        while(lo < hi){
            int mid = (lo + hi) / 2;
            int t1 = recBin(mid-1,k-1);
            int t2 = recBin(high-mid,k);
            if(t1 < t2) lo = mid+1;
            else if(t1>t2) hi = mid-1;
            else lo = hi = mid;
        }
        ret = min(ret,max(recBin(lo -1,k -1),recBin(high -lo,k))+1);
        ret = min(ret,max(recBin(hi -1,k -1),recBin(high -hi,k))+1);

        return ret;
    }
};


int main()
{
    Solution sol;
    printf("ret: %d\n",sol.superEggDrop(1,2));
    printf("ret: %d\n",sol.superEggDrop(2,6));
    printf("ret: %d\n",sol.superEggDrop(4,10000));
}