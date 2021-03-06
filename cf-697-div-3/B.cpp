#include <bits/stdc++.h>
using namespace std;


bool dp[1000001];

void gen(int val) {
    if (val >= 1000001) return;
    if (dp[val]) {
        return;
    }
    dp[val] = 1;
    gen(val + 2020);
    gen(val+2021);
}



int main(int argc, char const *argv[])
{
    gen(0);
    int test;
    int n;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        if(dp[n]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}