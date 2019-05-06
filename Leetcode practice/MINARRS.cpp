#include <iostream>
#include<string.h>
using namespace std;

const int maxn = 100050;

int ara[maxn];
int bit[32];

int main() {
    int test;
    int n;
    scanf("%d",&test);
    while(test--) {
        memset(bit,0,sizeof(bit));
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%d",ara+i);

            for(int j = 0;j<32;j++){
                bit[j] += ((ara[i]>>j) & 1);
            }

        }
        int mask = 0;
        for(int i = 0;i<32;i++){
            if(bit[i]>n/2) mask |= (1<<i);
        }
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum += (ara[i]^mask);
        }
        printf("%lld\n",sum);
    }
    return 0;
}