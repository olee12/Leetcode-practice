#include <bits/stdc++.h>
using namespace std;

void segmented_seive(int n, vector<int> &prime_container) {
    int nsqrt = sqrt(n);
    vector<int> primes;
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int s = min(nsqrt, 10000);
    vector<char> blocks(s);
    for (int k = 0; k * s <= n; k++) {
        int start = k * s;
        fill(blocks.begin(), blocks.end(), true);
        for (int p : primes) {
            // for the first batch, for example 2, we start marking with 4
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < s; j += p) blocks[j] = false;
        }
        if (k == 0) {
            blocks[0] = blocks[1] = false;
        }
        for (int i = 0; i < s && start + i <= n; i++)
            if (blocks[i]) prime_container.push_back(i + start);
    }
}

int main(int argc, char const *argv[]) {
    int n = 1010;
    vector<int> primes;
    segmented_seive(n, primes);
    printf("prime up to n:%d are: ", n);
    for (auto p : primes) {
        printf(" %d", p);
    }
    printf("\nTotal: %ld\n", primes.size());
    return 0;
}
