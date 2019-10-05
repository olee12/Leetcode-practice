#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row,col;
        if ((row = matrix.size())==0 || (col=matrix[0].size())==0) return 0;
        vector<int> freq(col,0);
        int ans = 0;
        for(int i = 0;i<row;i++) {
            for(int j = 0;j<col;j++){
                if(matrix[i][j]=='1')freq[j]++;
                else freq[j]=0;
            }
            ans = max(ans,histogram(freq));
        } 
        return ans;
    }

    int histogram(vector<int> &array) {
        if (array.size()==0) return 0;
        stack<int> st;
        int maxRec = numeric_limits<int>::min();
        int i = 0;
        int n = array.size();
        st.push(i);
        for(i = 1;i<n;) {
            if(st.size()==0 || array[i] >= array[st.top()]) st.push(i++);
            else {
                int pos = st.top();
                st.pop();
                int area = array[pos] * (st.size() ? i - st.top()-1 : i);
                maxRec = max(maxRec,area);
            }
        }
        while (st.size())
        {
            int pos = st.top();
            st.pop();
            int area = array[pos] * (st.size() ? i - st.top()-1 : i);
            maxRec = max(maxRec,area);
        }
        return maxRec;
    }
};

int main() {
    Solution sol;
    // testHistogram(sol);
}

