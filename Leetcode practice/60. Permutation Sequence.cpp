#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    char findNext(int n,int &mask,int offset){
        int cnt = 0;
        
        for(int i = 1;i<=n;i++){
            if(mask & (1<<i)) continue;
            cnt++;
            if(cnt == offset){
                mask |= (1<<i);
                return '0' + i;
            }
        }
        return 'e';
    }

    string getPermutation(int n, int k) {

        vector<int> fact(n+1,1);
        for(int i = 1;i<=n;i++) fact[i] = fact[i-1] * i;
        int mask = 0;
        string ret = "";

        int base = k;

        for(int i = n;i>=1;i--){
            int right = (base - 1) / fact[i - 1];
            char ch = findNext(n,mask,right+1);
            base -= right * fact[i-1];
            ret.push_back(ch);
        }
        return ret;
    }
};
int main(){
    Solution sol;

    int n,k;
    while(cin>>n>>k) {
        string ret = sol.getPermutation(n,k);
        cout<<ret<<endl;
    }
}