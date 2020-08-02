#include <bits/stdc++.h>
using namespace std;
const int INSERT = 1;
const int GET = 2;
bool isPriorityQueue(vector<pair<int,int> > &inp) {
    priority_queue<int> q;
    for(auto &val : inp) {
        if(val.first==INSERT) {
            q.push(val.second);
        }else {
            if(q.size()==0 || val.second!=q.top()) return false;
            q.pop();
        }
    }
    return true;
}

bool isStack(vector<pair<int,int> > &inp) {
    stack<int> st;
    for(auto &val: inp) {
        if(val.first == INSERT) {
            st.push(val.second);
        }else{
            if(st.size()==0 || st.top()!=val.second) return false;
            st.pop();
        }
    }
    return true;
}

bool isQueue(vector<pair<int,int> > &inp) {
    queue<int> q;
    for(auto &val: inp) {
        if(val.first == INSERT) {
            q.push(val.second);
        }else {
            if(q.size()==0 || q.front()!=val.second) return false;
            q.pop();
        }
    }
    return true;
}
string process(vector<pair<int,int> > &inp) {
    int isPrio = isPriorityQueue(inp);
    int isSt = isStack(inp);
    int isQ = isQueue(inp);
    int guess = isPrio + isSt + isQ;
    if(guess == 0) return "impossible";
    else if(guess > 1) return "not sure";
    else if(isPrio) return "priority queue";
    else if(isSt) return "stack";
    else if(isQ) return "queue";
    else assert(0);
}
int main() {
    // freopen("./inp/inp.txt", "r", stdin);
    int n;
    while(scanf("%d", &n)==1) {
        vector<pair<int,int>> inp(n, {0,0});
        for(int i = 0;i<n;i++) {
            scanf("%d %d", &inp[i].first, &inp[i].second);
        }
        printf("%s\n", process(inp).c_str());
    }
    return 0;
}