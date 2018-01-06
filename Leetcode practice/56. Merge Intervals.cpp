#include <bits/stdc++.h>
using namespace std;

// * Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool comp(Interval a, Interval b)
{
    return a.start < b.start;
}
class Solution
{

  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> ret;
        if(intervals.size()==0) return ret;
        sort(intervals.begin(), intervals.end(), comp);
        
        int curr = 0;
        ret.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++){
            if(ret[curr].end>=intervals[i].start){
                ret[curr].end = max(ret[curr].end,intervals[i].end);
            }else {
                ret.push_back(intervals[i]);
                curr++;
            }
        }
        return ret;
    }
};

int main()
{
    
}