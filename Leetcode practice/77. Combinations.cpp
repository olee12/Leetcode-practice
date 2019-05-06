#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
  public:
    int nth = 0;
    int size = 0;
    vector<vector<int>> ret;

    vector<vector<int>> combine(int n, int k)
    {
        nth = n;
        size = k;
        ret.clear();
        vector<int> state;
        state.clear();
        rec(1, state);
        return ret;
    }

    void rec(int pos, vector<int> &state)
    {
        if (state.size() == size)
        {
            ret.push_back(state);
            return;
        }

        if (pos > nth)
        {
            return;
        }

        for (int i = pos; i <= nth; i++)
        {
            state.push_back(i);
            rec(i + 1, state);
            state.pop_back();
        }
    }
};


int main()
{
    Solution sol;

    int n, k;
    while (cin >> n >> k)
    {
        vector<vector<int>> ret = sol.combine(n,k);

        for (vector<int> vec : ret)
        {
            printf("len %d: ", vec.size());
            for (auto a : vec)
            {
                printf("%d ", a);
            }
            printf("\n");
        }
    }
}