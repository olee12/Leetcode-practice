#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // printf("height: { ");
        // for(int i = 0;i<heights.size();i++) {
        //     printf(" %d",heights[i]);
        // }
        // printf(" }\n");
        stack<int> st;
        int ret = 0, mx = 0, n = heights.size();
        int h;
        for(int i = 0;i<=n;i++){
            if (i == n) h = 0;
            else h = heights[i];
            while(st.size() > 0 && heights[st.top()] > h) {
                int t = st.top();
                st.pop();
                ret = heights[t] * (st.size() ? i - st.top() - 1 : i);
                mx = max(mx,ret);
            }
            st.push(i);
        }
        return mx;        
    }
};


int main() {
    vector< vector<int> > tests = {
        {1,2,3,4,3,2,1},
        {1,2,3,4},
        {1,1,2,3,1,2,2,2},
        {1,0,3}
    };

    Solution sol;
    for(auto vec : tests) {
        printf("%d\n", sol.largestRectangleArea(vec));
    }
    // vector<int> v1 ={1,0,3};
    // printf("%d\n",sol.largestRectangleArea(v1));

}