#include <bits/stdc++.h>
using namespace std;


int main() {
    int test;
    long long n;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%lld", &n);
        if (n % 2) {
            printf("YES\n");
            continue;
        }

        while(n > 1 && (n%2==0)) {
            n/=2;
        }
        if (n>1) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
    return 0;
}