#include <bits/stdc++.h>
using namespace std;

struct Result
{
    int k, r, c;
};

Result *getResult(vector<vector<int>> mat, int N)
{
    Result *ret = new Result();
    ret->r = ret->c = ret->k = 0;

    for (int i = 0; i < N; i++)
    {
        unordered_map<int, bool> row_map;
        unordered_map<int, bool> col_map;
        bool row_flag = false;
        bool col_flag = false;
        for (int j = 0; j < N; j++)
        {
            int &val = mat[i][j];
            if (i == j)
                ret->k += mat[i][j];
            if (!row_flag && row_map.find(val) != row_map.end())
            {
                row_flag = true;
                ret->r++;
            }
            row_map[val] = true;
        }
        for (int j = 0; j < N; j++)
        {
            int &val = mat[j][i];
            if (!col_flag && col_map.find(val) != col_map.end())
            {
                col_flag = true;
                ret->c++;
            }
            col_map[val] = true;
        }
    }
    return ret;
}

int main()
{
    int test;
    int cas = 1;
    scanf("%d", &test);
    while (test--)
    {
        int N;
        scanf("%d", &N);
        vector<vector<int>> mat(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        Result *ret = getResult(mat, N);
        printf("Case #%d: %d %d %d\n", cas++, ret->k, ret->r, ret->c);
    }
    return 0;
}