#include <bits/stdc++.h>
using namespace std;

class SparseVector
{
public:
    vector<pair<int, int>> vec;
    SparseVector(vector<int> &nums)
    {
        this->vec = vector<pair<int, int>>();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                vec.push_back({i, nums[i]});
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        long long ret = 0;

        vector<pair<int, int>> &a = this->vec;
        vector<pair<int, int>> &b = vec.vec;
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size())
        {
            auto &p1 = a[i];
            auto &p2 = b[j];
            if (p1.first == p2.first)
            {
                ret += (long long)p1.second * p2.second;
                i++;
                j++;
            }
            else if (p1.first > p2.first)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
