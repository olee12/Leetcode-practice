#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
    set<pair<int, int>> memo;

    MyCalendar()
    {
        memo.clear();
    }
    bool book(int start, int end)
    {
        if (memo.size() == 0)
        {
            memo.insert({start, end});
            return true;
        }
        auto nd = memo.upper_bound({start, end});
        bool r = true;
        bool l = true;
        if (nd != memo.end())
        {
            r = start < nd->first && end <= nd->first;
        }
        if (nd != memo.begin() || nd == memo.end())
        {
            nd--;
            l = start >= nd->second && nd->second < end;
        }
        if (l && r)
        {
            memo.insert({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main(int argc, char const *argv[])
{

    MyCalendar *cal = new MyCalendar();
    assert(cal->book(10, 20) == true);
    assert(cal->book(15, 25) == false);
    assert(cal->book(20, 30) == true);
    assert(cal->book(1, 2) == true);
    assert(cal->book(2, 3) == true);
    assert(cal->book(5, 6) == true);
    assert(cal->book(4, 5) == true);
    assert(cal->book(6, 11) == false);
    return 0;
}
