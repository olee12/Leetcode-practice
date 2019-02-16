#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
#define mod 1000000007

int main()
{
    //freopen("in0.txt", "r", stdin);
    //freopen("out0.txt", "w", stdout);
    int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int da, db;
        scanf("%d : %d", &da, &db);
        int s = (a + b + c)/2;
        double area = sqrt(1.0 * s * (s-a) * (s-b) * (s-c)) / 4.0;
        printf("Case %d: %.2lf\n", tst++, area);
    }
    return 0;
}
