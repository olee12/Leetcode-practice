#include <bits/stdc++.h>
using namespace std;
typedef long long int i64;
const long long int base = 100003;
const long long int mod = 100000000019;

class Solution {
   public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        return binarySearch(n, paths);
    }

    int binarySearch(int n, vector<vector<int>>& paths) {
        vector<vector<i64>> hashVecs;
        // return 0;
        int low = 0;
        int high = numeric_limits<int>::max();
        for (auto& p : paths) {
            cout << p.size() << endl;
            high = min(high, (int)p.size());
            hashVecs.push_back(vector<i64>(p.size(), 0));
        }
        printf("olee1\n");
        // if (high == 0) return 0;
        printf("olee\n");
        // return 0;
        int bound = 0;
        while (low <= high) {
            int mid = (low + high) / 2;

            printf("low: %d high: %d ret: %d\n", low, high, findMatch(mid, paths, hashVecs, ::base, ::mod));
            if (findMatch(mid, paths, hashVecs, ::base, ::mod) == false) {
                high = mid - 1;
                // bound = mid;
            } else {
                bound = mid;
                low = mid + 1;
            }
        }
        return bound;
    }

    bool findMatch(int len, vector<vector<int>>& paths, vector<vector<i64>> hashVecs, i64 base, i64 mod) {
        if (len == 0) return true;
        i64 pw = 1;
        for (int i = 1; i < len; i++) pw = (pw * base) % mod;
        hashAll(len, paths, hashVecs, pw, base, mod);
        // printf("olee");
        unordered_map<i64, bool> tracker;
        unordered_map<i64, bool> common;
        tracker.clear();
        common.clear();

        for (int i = len - 1; i < hashVecs[0].size(); i++) tracker[hashVecs[0][i]] = true;

        for (int j = 1; j < hashVecs.size(); j++) {
            common.clear();
            for (int i = len - 1; i < hashVecs[j].size(); i++) {
                i64 it = hashVecs[j][i];
                if (tracker.find(it) != tracker.end()) {
                    common[it] = true;
                }
            }
            // printf("olee");
            if (common.size() == 0) return false;
            // swap(common, tracker);
            tracker = common;
        }
        printf("tracker: ");
        for (auto it : tracker) printf(" %d", it.first);
        printf("\n");
        return true;
    }

    void hashAll(int len, vector<vector<int>>& paths, vector<vector<long long int>>& hashVecs, long long int pw, long long int base, long long int mod) {
        // printf("\n printall\n");
        for (int i = 0; i < paths.size(); i++) {
            hashPath(len, paths[i], hashVecs[i], pw, base, mod);

            printf("--- pw: %lld, len: %d path : %d\n", pw, len, i);
            for (int j = 0; j < hashVecs[i].size(); j++) printf("%lld ", hashVecs[i][j]);
            printf("\n");
        }
    }

    void hashPath(int len, vector<int>& path, vector<long long int>& hashVec, long long int pw, long long int base, long long mod) {
        long long hash = hashPrefix(len, path, base, mod);
        hashVec[len - 1] = hash;
        for (int i = len; i < path.size(); i++) {
            hashVec[i] = hashVec[i - 1] - ((path[i - len] * pw) % mod);
            hashVec[i] = (hashVec[i] + mod) % mod;
            hashVec[i] = (hashVec[i] * base) % mod;
            hashVec[i] = (hashVec[i] + path[i]) % mod;
        }
    }
    long long int hashPrefix(int len, vector<int>& path, long long int base, long long int mod) {
        long long pw = 1;
        long long hash = 0;
        for (int i = len - 1; i >= 0; i--) {
            hash = (hash + ((path[i] * pw) % mod)) % mod;
            pw = (pw * base) % mod;
        }
        return hash;
    }
};

int main(int argc, char const* argv[]) {
    /* code */
    Solution sol;

    vector<vector<int>> paths = {
        {1, 2, 3, 4},
        {4, 1, 2, 3},
        {4}};
    cout << "sol: << \n"
         << sol.longestCommonSubpath(5, paths) << endl;
    return 0;
}
