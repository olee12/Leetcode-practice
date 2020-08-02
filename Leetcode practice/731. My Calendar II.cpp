#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    vector<vector<pair<int,int> > > slot;
    int k = 2;
    MyCalendarTwo() {
        slot = vector<vector<pair<int,int> > >(k, vector<pair<int,int> >());
    }
    
    bool book(int start, int end) {

        for(int i = 0;i < k; i++) {
            auto &events = slot[i];
            for(auto &e : events) {
                bool overlap = max(e.first, start) < min(e.second, end);
                if (overlap && i == 0) {
                    return false;
                }else if (overlap) {
                    slot[i-1].push_back({max(e.first, start), min(e.second, end)});
                }
            }
        }
        slot[k-1].push_back({start,end});
        return true;
    }
    
};


int main(int argc, char const *argv[])
{
    /* code */
    MyCalendarTwo *cal = new MyCalendarTwo();
    assert(cal->book(10, 20) == true); // returns true
    assert(cal->book(50, 60) == true); // returns true
    assert(cal->book(10, 40) == true); // returns true
    assert(cal->book(5, 15) == false);  // returns false
    assert(cal->book(5, 10) == true);  // returns true
    assert(cal->book(25, 55) == true); // returns true
    return 0;
}
