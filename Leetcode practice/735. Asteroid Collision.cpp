#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0;i<asteroids.size();i++){
            int &cur = asteroids[i];
            if(cur >= 0){
                st.push(cur);
            }else {
                bool destroied = false;
                cur = cur * -1;
                while(st.size() && st.top()>=0){
                    if(st.top() < cur) st.pop();
                    else if(st.top() == cur) {
                        destroied = true;
                        st.pop();
                        break;
                    }else {
                        destroied = true;
                        break;
                    }
                }
                if(destroied==false) st.push(cur * -1);
            }
            // printf("i %d stack size: %d\n",i,st.size());
        }
        // printf("-----");
        vector<int> ret;
        while(st.size()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(),ret.end());   
        return ret;
    }
};


int main() {
    vector<int> astroid = {8, -8};
    Solution sol;
    vector<int> result = sol.asteroidCollision(astroid);
    for(auto it : result) {
        printf("%d ",it);
    }
    printf("\n");
}