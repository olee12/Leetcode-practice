#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
vector<char> blocks;

void seive(long long n) {
    // printf(" %lld\n", n);
    long long nsqrt = sqrt(n);
    // printf("nsqrt: %lld\n", nsqrt);
    vector<bool> is_prime(nsqrt + 2, true);
    for (long long i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= nsqrt; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return;
}

pair<pair<long long, long long>, pair<long long, long long>> primeDistance(long long L, long long R) {
    pair<pair<long long, long long>, pair<long long, long long>> ret = {{-1, -1}, {-1, -1}};
    // cout << "diff: " << (R - L + 1) << endl;
    fill(blocks.begin(), blocks.begin() + (R - L + 1), true);

    for (long long p : primes) {
        long long start_idx = (L + p - 1) / p;
        long long j = max(start_idx, p) * p - L;
        for (; j <= R - L + 1; j += p) {
            // if (j >= blocks.size()) cout << "fuck: " << j << endl;
            blocks[j] = false;
        }
    }
    if (L == 1) {
        blocks[0] = false;
    }

    long long last = -1;
    long long mxx = 0;
    long long mnn = numeric_limits<long long>::max();
    for (long long l = L; l <= R; l++) {
        // if ((l - L) >= blocks.size()) {
        //     printf("fuck: %lld, block size: %ld\n", l - L, blocks.capacity());
        // }
        if (blocks[l - L]) {
            // cout << " p:" << l << " ";
            if (last == -1) {
                last = l;
                continue;
            }
            if (l - last < mnn) {
                mnn = l - last;
                ret.first = {last, l};
            }
            if (l - last > mxx) {
                mxx = l - last;
                ret.second = {last, l};
            }
            last = l;
        }
    }
    // cout << endl;
    return ret;
}

int main(int argc, char const *argv[]) {
    blocks = vector<char>(1000000 + 2);
    seive((1ll << 31) - 1);
    // printf("%d\n", primes.size());
    // primeDistance((1ll << 31) - 1000, (1ll << 31) - 1);

    long long L, R;
    while (scanf("%lld %lld", &L, &R) == 2) {
        pair<pair<long long, long long>, pair<long, long>> ret = primeDistance(L, R);
        if (ret.first.first == -1) {
            printf("There are no adjacent primes.\n");
        } else {
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", ret.first.first, ret.first.second,
                   ret.second.first, ret.second.second);
        }
    }
    return 0;
}
