#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i = 1;i<=9;i++){
            rec(i,n,ret);
        }
        return ret;
    }
    vector<int> GO(int n) {
        
        vector<int> ret(n);
        //printf("%d\n",ret.size());
        int current = 1;
        for(int i = 0;i<n;i++){
            ret[i] = current;
            if(current * 10 <= n){
                current *= 10;
            }
            else {
                if(current >= n){
                    //printf("[Olee %d]",current);
                    current /= 10;
                }
                current++;
                while(current % 10==0) current /= 10; 
            }
        }
        return ret;
    }
    void rec(int now,int end,vector<int> &ret){
        if( now > end) return ;
        ret.push_back(now);
        for(int i = 0;i<=9;i++){
            if(now * 10 + i > end) return ;
            
            rec(now * 10 + i,end,ret);
        }

    }
};


int main()
{
    Solution sol;

    vector<int> vec = sol.lexicalOrder(0);
    for(int a: vec){
        printf(" %d",a);
    }

}