#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        auto comp = [](vector<int> &p1, vector<int> &p2) -> bool {
            if (p1[0] == p2[0])
                return p1[1] < p2[1];
            else
                return p1[0] > p2[0];
        };
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> ret(people.size(), vector<int>(2, -1));
        for (int i = 0; i < people.size(); i++)
        {
            addPeople(ret, people[i], i);
        }
        return ret;
    }

    void addPeople(vector<vector<int>> &ret, vector<int> p, int prev)
    {
        int pos = p[1];
        for (int i = prev; i > pos; i--)
        {
            ret[i] = ret[i - 1];
        }
        ret[pos] = p;
        cout << "[";
        for (auto p : ret)
        {
            printf(" [%d, %d]", p[0], p[1]);
        }
        printf("]\n");
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution sol;
    cout << "[";
    for (auto p : sol.reconstructQueue(people))
    {
        printf(" [%d, %d]", p[0], p[1]);
    }
    printf("]\n");
    return 0;
}
