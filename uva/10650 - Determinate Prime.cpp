#include <bits/stdc++.h>
using namespace std;

bool compare(vector<vector<int>> a, vector<vector<int>> b) {
    if (a.size() != b.size()) return true;

    printf("len of a: %d, len of b: %d\n", a.size(), b.size());
    map<vector<int>, bool> uniq;
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        uniq[a[i]] = true;
        if (a[i] != b[i]) {
            cout << "a: ";
            for (int it : a[i]) printf(" %d", it);
            cout << "\n";
            cout << "b: ";
            for (int it : b[i]) printf(" %d", it);
            cout << "\n";
            return true;
        }
    }
    return false;
    printf("\n\nnice a\n");
    for (auto it : a) {
        cout << "a: ";
        for (int x : it) printf(" %d", x);
        cout << "\n";
    }

    printf("\n\nnice b\n");
    for (auto it : b) {
        cout << "b: ";
        for (int x : it) printf(" %d", x);
        cout << "\n";
    }
    for (auto it : b) {
        if (uniq.find(it) == uniq.end()) {
            printf("fuck: ");
            for (int x : it) {
                printf(" %d", x);
            }
            printf("\n");
        }
    }
    return false;
}
void seive(int n, vector<int> &primes) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = 0;
    int nsqrt = sqrt(n) + 1;
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            // primes.push_back(i);
            // printf("i %d\n", i);
            for (int j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (is_prime[i]) {
            // printf(" %d", i);
            primes.push_back(i);
        }
    // printf("\n");
}
vector<vector<int>> fixed(int l, int r, vector<int> &primes) {
    if (l > r) swap(l, r);
    vector<vector<int>> totalRet;
    vector<int> ret;
    int s = 0, e = 0;
    bool flag = false;
    for (int i = 2; i < primes.size(); i++) {
        if (primes[i] - primes[i - 1] == primes[i - 1] - primes[i - 2] && flag == false) {
            s = i - 2;
            e = i;
            flag = true;
            // printf("%d %d %d\n", primes[i - 2], primes[i - 1], primes[i]);
        } else if (primes[i] - primes[i - 1] == primes[i - 1] - primes[i - 2] && flag) {
            e++;
        } else {
            if (flag && s != e && primes[s] >= l && primes[e] <= r) {
                ret.clear();
                // printf("%d", primes[s]);
                ret.push_back(primes[s]);
                for (int j = s + 1; j <= e; j++) {
                    // printf(" %d", primes[j]);
                    ret.push_back(primes[j]);
                }
                // printf("\n");
                totalRet.push_back(ret);
            }

            flag = false;
        }
        // printf("s %d e %d\n", s, e);
    }
    return totalRet;
}
void PrintDeterminatePrime(int l, int r, vector<int> &primes) {
    if (l > r) swap(l, r);
    map<int, bool> printed;
    printed.clear();
    // vector<vector<int>> totalRet;
    // int li = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
    // int ri = upper_bound(primes.begin(), primes.end(), r) - primes.begin();
    // printf("li, ri: %d %d\n", li, ri);
    // if (li >= primes.size()) return;
    int li = 0, ri = 0;
    while (li < primes.size() && primes[li] < l) {
        li++;
    }
    // cout << li << " " << ri << endl;
    int last = 0;
    vector<int> ret;
    for (int i = 2; i < primes.size(); i++) {
        int a = primes[i - 1];
        int b = primes[i];
        // if (b > r) break;
        int diff = b - a;
        // printf("%d %d %d %d\n", a, b, diff, last);
        if (diff == last) {
            // if (ret.size() == 0) ret.push_back(a);
            ret.push_back(b);
            // assert(printed.find(b) == printed.end());
        } else {
            if (ret.size() >= 3) {
                // print
                if (!(ret[0] >= l && ret.back() <= r)) {
                    ret.clear();
                    continue;
                }
                for (int j = 0; j < ret.size(); j++) {
                    printed[ret[j]] = 1;
                    if (j) printf(" ");
                    printf("%d", ret[j]);
                }
                printf("\n");
                // totalRet.push_back(ret);
            }
            ret.clear();
            last = diff;
            ret.push_back(a);
            ret.push_back(b);
            // assert(printed.find(b) == printed.end());
            // assert(printed.find(a) == printed.end());
        }
    }
    if (ret.size() >= 3) {
        // print
        if (!(ret[0] >= l && ret.back() <= r)) {
            ret.clear();
            return;
        }
        // if (ret.back() > r) return totalRet;
        for (int j = 0; j < ret.size(); j++) {
            if (j) printf(" ");
            printf("%d", ret[j]);
        }
        printf("\n");
        // totalRet.push_back(ret);
    }
    return;
}

int main(int argc, char const *argv[]) {
    /* code */
    vector<int> primes;
    seive(33000, primes);
    int l, r;
    while (scanf("%d %d", &l, &r) == 2) {
        if (l == r && l == 0) return 0;
        // compare(PrintDeterminatePrime(l, r, primes), fixed(l, r, primes));
        PrintDeterminatePrime(l, r, primes);
    }

    // for (int i = 0; i < 32000; i++) {
    //     for (int j = i; j < 32000; j++)
    //         if (compare(PrintDeterminatePrime(i, j, primes), fixed(i, j, primes))) {
    //             printf("i,j %d %d\n", i, j);
    //             assert(false);
    //         }
    // }
    return 0;
}
