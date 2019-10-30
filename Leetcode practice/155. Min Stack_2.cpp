#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long min;
public:
    /** initialize your data structure here. */

    MinStack() {
        while(st.size()) st.pop();
        min = numeric_limits<long long> :: min();
    }
    
    void push(int x) {
        if(!st.size()) {
            st.push(0);
            min = x;
            return ;
        }    
        st.push(x - min);
        if(x < min) min = x;
    }
    
    void pop() {
        if(!st.size()) return ;
       long long top = st.top();
       if (top < 0) min = min - top;
       st.pop(); 
    }
    
    int top() {
       long long top = st.top();
       if(top>0) return top + min;
       return min; 
    }
    
    int getMin() {
       return min; 
    }
};

int main() {

}