#include <bits/stdc++.h>
using namespace std;


long long prizeMoney(vector<vector<int>> &days) {

    multiset<int> urn;
    long long ret = 0;
    for(auto &day:days) {
        for(int &v : day) {
            urn.insert(v);
        }
        auto beg = urn.begin();
        auto end = urn.end();
        end--;
        ret += (*end - *beg);
        urn.erase(beg);
        urn.erase(end);
    }
    return ret;
}


int main() {
    // freopen("./uva/inp/inp.txt", "r", stdin);
    int n;
    while(scanf("%d", &n)==1 && n > 0) {
        vector< vector<int> > days;
        for(int d = 1; d <= n; d++) {
            int len = 0;
            scanf("%d", &len);
            vector<int> day(len, 0);
            for(int i = 0;i<len;i++){
                scanf("%d", &day[i]);
            };
            days.push_back(day);
        }
        printf("%lld\n", prizeMoney(days));
    }
}