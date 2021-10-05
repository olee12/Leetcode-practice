#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    class line
    {
    public:
        int x, y;
        int index;
        int sign;
        line(int x = 0, int y = 0, int index = 0, int sign = 0)
        {
            this->x = x;
            this->y = y;
            this->index = index;
            this->sign = sign;
        }
        bool operator<(const line &a) const
        {
            if (x != a.x)
            {
                return x < a.x;
            }
            else if (sign != a.sign)
            {
                return sign > a.sign;
            }
            if (y != a.y)
            {
                return y > a.y;
            }
            else
                return sign > a.sign;
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<line> lines;
        for (int i = 0; i < buildings.size(); i++)
        {
            auto &b = buildings[i];
            lines.push_back(line(b[0], b[2], i, 1));
            lines.push_back(line(b[1], b[2], i, -1));
        }
        sort(lines.begin(), lines.end());
        set<pair<int, int>, greater<pair<int, int>>> st;
        vector<vector<int>> ret;
        int curY = 0;
        for (int i = 0; i < lines.size(); i++)
        {
            line &l = lines[i];

            // remove
            if (l.sign == -1)
            {
                pair<int, int> rm = {l.y, l.index};
                st.erase(rm);
                if (st.size())
                {
                    auto top = st.begin();
                    if (top->first < curY)
                    {
                        ret.push_back({buildings[rm.second][1], top->first});
                    }
                }
                else
                {
                    ret.push_back({l.x, 0});
                }
                if (ret.size() >= 2)
                {
                    auto last_last = ret[ret.size() - 2];
                    auto last = ret[ret.size() - 1];
                    if (last[0] == last_last[0])
                    {
                        ret.pop_back();
                        ret.pop_back();
                        ret.push_back({last[0], min(last[1], last_last[1])});
                    }
                }
                curY = st.begin()->first;
                continue;
            }

            // insert
            if (st.size() == 0 || st.begin()->first < l.y)
            {
                ret.push_back({l.x, l.y});
            }
            st.insert({l.y, l.index});
            curY = st.begin()->first;
        }
        return ret;
    }
};
int main()
{
    vector<vector<int>> buildings = {{0, 5, 7}, {5, 10, 7}, {5, 10, 12}, {10, 15, 7}, {15, 20, 12}, {20, 25, 7}};
    // vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
    Solution sol;
    vector<vector<int>> ret = sol.getSkyline(buildings);
    for (auto it : ret)
    {
        cout << it[0] << " " << it[1] << " " << endl;
    }
}