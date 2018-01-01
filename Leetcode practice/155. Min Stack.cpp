#include <bits/stdc++.h>
using namespace std;



class MinStackWith2Stack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> mst; 

    MinStack() {
       
        while(st.size()) st.pop();
        while(mst.size()) mst.pop(); 
       // printf("I am created");

    }
    //"C:/Program Files (x86)/CodeBlocks/MinGW/lib/gcc/mingw32",
    void push(int x) {
        st.push(x);
        if(mst.empty()==true){
            mst.push(x);
        }else{
            mst.push(min(mst.top(),x));
        }
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};

/** only one stack used*/
class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<long long> st;
    long long min = numeric_limits<long long>::min();


    MinStack() {
        while(st.empty()==false) st.pop();
    }
    void push(int x) {
        if(st.empty()==true){
            st.push(0);
            min =  x;
        }
        else{
            st.push(x - min);
            if(x<min) min = x;
        }
    }
    void pop() {
        int t = st.top();
        st.pop();
        if(t<0) min = min - t;
    }
    
    int top() {
        if(st.top()>0) return st.top() + min;
        else return min;
    }
    
    int getMin() {
        return min;
    }
};

int main()
{
    MinStack mn;
    mn.push(5);
    mn.push(3);
    mn.push(1);
    mn.push(4);
    printf("%d\n",mn.getMin());
}   
