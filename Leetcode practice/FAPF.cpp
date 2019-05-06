#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;

long long ara[maxn];

int main() {
    int test,n;
    int q;
    int x,y;
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d",&n,&q);

        vector<long long> vec;
        for(int i = 1;i<=n;i++) {
            scanf("%lld",ara+i);
            vec.push_back(ara[i]);
        }
        sort(vec.begin(),vec.end());

        long long ret = 0; int len = 0;
        long long mn,mx;
        for(int ca = 1;ca<=q;ca++){
            int a,b;
            scanf("%d %d",&x,&y);
            // x = min(a,b);
            // y = max(a,b);
            mn = min(ara[x],ara[y]);
            mx = max(ara[x],ara[y]);
            ret = abs(ara[x]-ara[y]) + y - x;
            len = 0;

            len =  upper_bound(vec.begin(),vec.end(),mx) - lower_bound(vec.begin(),vec.end(),mn);

            // for(int i = 1;i<=n;i++){
            //     if(ara[i]>=mn && ara[i]<=mx ) len++;
            // }
            printf("%lld %d\n",ret,len);
        }
    }
    return 0;
}