#include <bits/stdc++.h>
using namespace std;
// shit problem

class Solution {
   public:
    vector<int> beautifulArray(int n) {
        vector<int> ret = {1};
        while (ret.size() < n) {
            vector<int> tmp;
            for (int i : ret)
                if (i * 2 - 1 <= n) tmp.push_back(i * 2 - 1);
            for (int i : ret)
                if (i * 2 <= n) tmp.push_back(i * 2);
            ret = tmp;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    for (auto it : sol.beautifulArray(5)) {
        printf(" %d", it);
    }
}