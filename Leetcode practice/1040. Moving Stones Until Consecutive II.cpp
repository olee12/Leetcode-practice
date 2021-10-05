#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        int minMove = numeric_limits<int>::max();
        sort(stones.begin(), stones.end());
        int gap = stones[n - 1] - stones[0] - n + 1;

        // if there is gap in only one side then minimum move is min(2, gap size)
        if (stones[n - 1] - stones[n - 2] - 1 == gap || stones[1] - stones[0] - 1 == gap) {
            // 3,4,5,6,_,_,_,_,_,_13 --> 4,5,6,_,3,_,_,_,_,13 --> 4,5,6,13,3
            minMove = min(2, gap);
        } else {
            // we do a simple sliding window with helo of binary search
            for (int i = 0; i < n; i++) {
                int inside = upper_bound(stones.begin() + i, stones.end(), stones[i] + n - 1) - stones.begin() - i;
                minMove = min(minMove, n - inside);
            }
        }
        return {minMove, max(stones[n - 2] - stones[0] - n + 2, stones[n - 1] - stones[1] - n + 2)};
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;

    vector<int> t1 = {6, 5, 4, 3, 10};
    cout << "t1: ";
    for (auto it : sol.numMovesStonesII(t1)) cout << it << " ";
    cout << endl;

    return 0;
}
