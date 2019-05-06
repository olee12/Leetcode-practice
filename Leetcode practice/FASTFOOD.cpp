#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 100050;
long long a[maxn];
long long b[maxn];
int main(){
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        a[0] = 0;
        for(int i = 1;i<=n;i++){
            scanf("%lld",a+i);
            a[i] = a[i] + a[i-1];
        }
        b[0] = 0;
        for(int i = 1;i<=n;i++){
            scanf("%lld",b+i);
        }
        b[n+1] = 0;
        for(int i = n;i>=0;i--){
            b[i] = b[i] + b[i+1];
        }


        long long ret = 0;

        for(int i = 1;i<=n;i++){
            ret = max(ret,a[i]+b[i+1]);
        }
        ret = max(ret,a[n]);
        ret = max(ret,b[0]);
        printf("%lld\n",ret);

    }
    return 0;
}