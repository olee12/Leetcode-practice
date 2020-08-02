#include <bits/stdc++.h>
using namespace std;

struct intv {
    int first,second,idx;
    bool operator < (const intv &b) const {
        if (first == b.first) {
            return second < b.second;
        }
        return first < b.first;
    }
};

string distributeWork(vector< intv > &intervals) {
    sort(intervals.begin(), intervals.end());
    string impossible = "IMPOSSIBLE";
    char cameron  = 'C';
    char jamie = 'J';
    intv cLast, jLast;
    string ret(intervals.size(), ' ');
    
    cLast = intervals[0];
    ret[cLast.idx] = cameron;
    jLast.first = jLast.second = 0;
    for(int i = 1;i<intervals.size();i++) {
        intv &current = intervals[i];
        if(current.first >= cLast.second) {
            ret[current.idx] = cameron;
            cLast = current;
        }else if(current.first >= jLast.second){
            ret[current.idx] = jamie;
            jLast = current;
        }else {
            return impossible;
        }
    }
    return ret;
}
int main() {
    int test, cas = 1;
    scanf("%d", &test);
    while(test--) {
        int N;
        scanf("%d", &N);
        vector<intv> intervals;
        for(int i = 0;i<N;i++) {
            intv interval;
            interval.idx = i;
            scanf("%d %d", &interval.first, &interval.second);
            intervals.push_back(interval);
        }
        printf("Case #%d: %s\n", cas++, distributeWork(intervals).c_str());
    }
    return 0;
}