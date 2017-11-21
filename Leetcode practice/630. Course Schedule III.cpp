#include <bits/stdc++.h>

using namespace std;
bool comp(vector<int> a,vector<int> b)
{
    return a[1] < b[1];
}


class Solution {
public:
    int scheduleCourse(vector< vector<int> >& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int> mxq;
        int count = 0;
        int tim = 0;
        for(vector<int> &v: courses){
            if(tim + v[0] <= v[1]){
                count+=1;
                tim += v[0];
                mxq.push(v[0]);
            }else if(mxq.size()>0 && mxq.top() > v[0]){
                tim+= v[0] - mxq.top();
                mxq.pop();
                mxq.push(v[0]);
            }
        }
        return count;
    }
};

int main()
{
   // printf("hello world");
    return 0;
}