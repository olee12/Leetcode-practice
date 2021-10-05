#include <bits/stdc++.h>
using namespace std;
/*
0 1 0 0 0 2 3 0 0 5

(1, 0),(1, 1)(3, 0)(1, 2)(1, 3), (2, 0)(1, 5)

2 3 0 0 2 0 0 1 0 0 
(1, 2),(1, 3),(2, 0)(1, 2)(2, 0), (1, 1) (2, 0)
[0,1,0,0,2,0,0]
[1,0,0,0,3,0,4]
*/
class SparseVector
{
public:
    vector<pair<int, int>> vec;
    int n = 0;
    SparseVector(vector<int> &nums)
    {
        int idx = 0;
        int prev = 0;

        vec = vector<pair<int, int>>();

        pair<int, int> cur;

        while (idx < nums.size())
        {
            pair<int, int> cur = {0, nums[idx]};
            while (idx < nums.size() && nums[idx] == cur.second)
            {
                idx++;
                cur.first++;
            }
            vec.push_back(cur);
        }
        n = nums.size();
    }
    void debug()
    {
        for (auto &it : vec)
        {
            cout << "( " << it.first << "," << it.second << ") ";
        }
        cout << endl;
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &b)
    {
        int idx = 0;
        int ptr = 0;
        long long ret = 0;
        while (idx < this->vec.size())
        {
            auto &p1 = this->vec[idx];
            while (p1.first > 0 && ptr < b.vec.size())
            {

                auto &p2 = b.vec[ptr];
                int w = min(p1.first, p2.first);

                // printf("%d %d, %d %d\n", p1.first, p2.first, p1.second, p2.second);
                p1.first -= w;
                p2.first -= w;

                if (p2.first == 0)
                {
                    ptr++;
                }
                ret += (long long)(w) * (long long)p1.second * (long long)p2.second;
            }

            if (p1.first == 0)
            {
                idx++;
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> vec1 = {0, 1, 0, 0, 2, 0, 0};
    vector<int> vec2 = {1, 0, 0, 0, 3, 0, 4};
    SparseVector *svec1 = new SparseVector(vec1);
    SparseVector *svec2 = new SparseVector(vec2);
    svec1->debug();
    svec2->debug();
    SparseVector vec2value = *svec2;
    cout << svec1->dotProduct(vec2value) << endl;
    return 0;
}
