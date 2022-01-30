#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
using namespace std;


class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int ans = A.size() + 1;
        int sum = 0;

        for(int i = 0;i<A.size();i++) {
            sum+=A[i];
            if(sum >= K) ans = min(ans, i + 1);
            while(pq.size() && (sum - pq.top().first) >= K) {
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == A.size() + 1 ? -1 : ans;
    }
};

int main() {
    vector<int> inp = {3,-2,5};
    Solution sol;
    printf("ans: %d\n",sol.shortestSubarray(inp, 4));
    printf("------------");
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater< pair<int, int> > > q;
    q.push({10, 5});
    q.push({10, 8});
    q.push({15, 10});
    q.push({9,4});
    q.push({9,2});
    while (q.size()) {
        printf("\n top : %d %d\n", q.top().first, q.top().second);
        q.pop();
    }
    
    return 0;
}