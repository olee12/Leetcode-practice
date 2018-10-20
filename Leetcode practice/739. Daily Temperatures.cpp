#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> ret(T.size(),0);

        for(int i = T.size() - 1;i>=0;i--){
            while(st.size() && T[i]>=T[st.top()]) st.pop();
            if(st.size()) ret[i] = st.top() - i;
            st.push(T[i]);
        }
        return ret;
    }
};



int main()
{

}