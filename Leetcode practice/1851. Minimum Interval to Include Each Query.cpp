#include <bits/stdc++.h>
using namespace std;

class compareClass
{
public:
    bool operator()(pair<pair<int, int>, int> const &a, pair<pair<int, int>, int> const &b)
    {
        int len1 = a.first.second - a.first.first + 1;
        int len2 = b.first.second - b.first.first + 1;
        return len1 > len2;
    }
};

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        vector<pair<pair<int, int>, int>> lines;
        for (int i = 0; i < intervals.size(); i++)
        {
            vector<int> &it = intervals[i];
            lines.push_back({{it[0], it[1]}, i});
        }
        sort(lines.begin(), lines.end(), [](const auto &a, const auto &b)
             {
                 if (a.first.first == b.first.first)
                 {
                     return a.first.second < b.first.second;
                 }
                 return a.first.first < b.first.first;
             });

        // sort(lines.begin(), lines.end(), less<pair<pair<int, int>, int>>());

        vector<pair<int, int>>
            qpoints;
        for (int i = 0; i < queries.size(); i++)
        {
            qpoints.push_back({queries[i], i});
        }
        sort(qpoints.begin(), qpoints.end());
        // printf("%d\n", qpoints[0] < qpoints[1]);

        // printf("intervals\n");
        // for (auto &it : lines)
        // {
        //     printf("index: %d, l: %d, r:%d\n", it.second, it.first.first, it.first.second);
        // }
        // printf("qpoints: \n");
        // for (auto &it : qpoints)
        // {
        //     printf("index %d, q: %d\n", it.second, it.first);
        // }

        // priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, less<pair<pair<int, int>, int>>> q;
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compareClass> q;

        vector<int> ret(queries.size(), -1);

        int ptr = 0;
        for (int i = 0; i < qpoints.size(); i++)
        {
            while (ptr < lines.size() && lines[ptr].first.first <= qpoints[i].first)
                q.push(lines[ptr++]);

            while (q.size() && q.top().first.second < qpoints[i].first)
                q.pop();

            if (q.size() && q.top().first.second >= qpoints[i].first)
            {
                auto &it = q.top();
                // printf("---i %d, q: %d, top: %d %d %d\n", i, qpoints[i].first, it.second, it.first.first, it.first.second);
                ret[qpoints[i].second] = it.first.second - it.first.first + 1;
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> lines = {{2, 3},

                                 {2, 5},
                                 {1, 8},
                                 {20, 25}};
    vector<int> q = {2, 19, 5, 22};
    Solution sol;
    vector<int> res = sol.minInterval(lines, q);

    for (int i = 0; i < res.size(); i++)
    {
        if (i)
            printf(" ");
        printf("i: %d [%d]", i, res[i]);
    }
    /* code */
    return 0;
}
