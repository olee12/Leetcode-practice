#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        Interval temp = Interval(newInterval.start, newInterval.end);

        deque<Interval> ret;

        int flag = false;
        for (auto &item : intervals)
        {
            if (flag)
                ret.push_back(item);
            else
            {
                if (item.start > temp.end)
                {
                    flag = true;
                    ret.push_back(temp);
                    ret.push_back(item);
                }
                else if (item.end < temp.start)
                {
                    ret.push_back(item);
                }
                else if ((temp.start >= item.start && temp.start <= item.end) ||
                         (temp.end >= item.start && temp.end <= item.end))
                {

                    temp.start = min(temp.start, item.start);
                    temp.end = max(temp.end, item.end);
                }
            }
        }
        if(flag == false){
            ret.push_back(temp);
        }
        return vector<Interval> {ret.begin(),ret.end()};
    }
};

/**
 * 
 * 
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]].

    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

CASE: 
---------- --------- ------------ ------------- ---------
      ----------

---------- --------- ------------ ------------- ---------
              -------------------------

---------- ---------               ------------- ---------   
                      -----------

----------          --------- ------------ ------------- ---------
            ------

----------          --------- ------------ ------------- ---------
            ------------

----------          --------- ------------ ------------- ---------
       ---------

                ---------- --------- ------------ ------------- ---------
  --------              
 * 
 */

int main()
{
    string str;
    while (cin >> str)
    {
        cout << str << endl;
    }
}
