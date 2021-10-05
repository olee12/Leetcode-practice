#include <bits/stdc++.h>
using namespace std;

void baseto(int n) {
    vector<int> ret;
    while (n != 0) {
        ret.push_back(n % -2);
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    for (auto i : ret) cout << i << ' ';
}

int main(int argc, char const *argv[]) {
    // cout << 8 % 3 << endl;
    // cout << -8 % 3 << endl;
    // cout << 8 % -3 << endl;
    // cout << -8 % -3 << endl;
    // cout << -11 % 5 << endl;
    // cout << 11 % -5 << endl;
    baseto(2);
    cout << "" << endl;
    return 0;
}
