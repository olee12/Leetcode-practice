#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int boys[maxn];
int girls[maxn];
int freq_boys[maxn];
int freq_girls[maxn];



int main(int argc, char const *argv[])
{
    /* code */

    int t;
    int k, a,b;

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &a, &b, &k);
        memset(freq_boys, 0, sizeof (int) * (a+2) );
        memset(freq_girls, 0, sizeof (int) * (b+2) );
        for(int i = 0;i<k;i++) {
            scanf("%d", boys + i);
            freq_boys[boys[i]]++;
        }
        for(int i = 0;i<k;i++) {
            scanf("%d", girls + i);
            freq_girls[girls[i]]++;
        }

        long long sum = 0;;
        for(int i = 0;i<k;i++) {
            int &b = boys[i];
            int &g = girls[i];
            // sum += k;
            sum += (k- freq_boys[b] - freq_girls[g] + 1);
            // printf("%d b:%d g:%d (fb: %d, fg:%d) %lld\n", i, b, g, freq_boys[b], freq_girls[g], sum);
        }
        printf("%lld\n", sum/2);


    }


    return 0;
}

