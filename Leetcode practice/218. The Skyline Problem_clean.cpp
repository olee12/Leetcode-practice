#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> points;
        for (auto &b : buildings)
        {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        sort(points.begin(), points.end());
        multiset<int> st = {0};
        int prev = 0, cur;
        vector<vector<int>> ret;
        for (auto &p : points)
        {
            // cout << p.first << " " << p.second << endl;
            if (p.second < 0)
                st.emplace(-p.second);
            else
                st.erase(st.find(p.second));
            cur = *st.rbegin();
            if (cur != prev)
            {
                ret.push_back({p.first, cur});
                prev = cur;
            }
        }
        return ret;
    }
};
int main()
{
    vector<vector<int>> buildings = {{1, 3, 2}, {1, 3, 1}, {1, 3, 3}};
    // vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
    Solution sol;
    vector<vector<int>> ret = sol.getSkyline(buildings);
    printf("\n");
    for (auto it : ret)
    {
        cout << it[0] << " " << it[1] << " " << endl;
    }
}