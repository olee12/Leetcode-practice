#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int totalFruit(vector<int> &tree)
    {
        int result = 0;
        vector<int> freq = vector<int>(tree.size(), 0);
        for (int i = 1; i < tree.size(); i++)
        {
            freq[i] += (tree[i] == tree[i - 1]) ? freq[i - 1] + 1 : 1;
        }
        pair<int, int> a, b;
        a = make_pair(-1, 0);
        b = make_pair(-1, 0);
        for (int i = 0; i < tree.size(); i++)
        {
            if (a.first == tree[i] || a.first == -1)
            {
                a.first = tree[i];
                a.second += 1;
            }
            else if (b.first == tree[i] || b.first == -1)
            {
                b.first = tree[i];
                b.second += 1;
            }
            else if (a.first == tree[i - 1])
            {
                b.first = tree[i];
                b.second = 0;
                b.second += 1;
                a.second = freq[i - 1];
            }
            else if (b.first == tree[i - 1])
            {
                a.first = tree[i];
                a.second = 0;
                a.second += 1;
                b.second = freq[i - 1];
            }
            if (a.second + b.second > result)
                result = a.second + b.second;
        }
        return result;
    }
    int totalFruit(vector<int> tree,int flag)
    {
        unordered_map<int, int> count;
        int res = 0, i = 0;
        for (int j = 0; j < tree.size(); ++j)
        {
            count[tree[j]]++;
            while (count.size() > 2)
            {
                count[tree[i]]--;
                if (count[tree[i]] == 0)
                    count.erase(tree[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main()
{
    vector<int> tree = {1, 0, 1, 4, 1, 4, 1, 2, 3};
    Solution sol;
    cout << "result : " << sol.totalFruit(tree) << endl;
    return 0;
}