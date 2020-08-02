#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    map<int,int> events;
    MyCalendarTwo() {
        events.clear();
    }
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        int booked = 0;
        for(auto &e: events) {
            booked +=e.second;
            if (booked ==3) {
                events[start]--;
                events[end]++;
                return false;
            }
        }
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
