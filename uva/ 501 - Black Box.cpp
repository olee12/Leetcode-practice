#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> inp, vector<int> pos)
{
    if(inp.size() <= 0) {
        return {};
    }
    vector<int> ret;
    multiset<int> multi_set;
    multiset<int>:: iterator iter;
    multi_set.clear();
    multi_set.insert(inp[0]);
    iter = multi_set.begin();
    int get_index = 0;

    for (int i = 1; i < inp.size(); i++)
    {
        // printf("i: %d\n", i);
        while (get_index < pos.size() && pos[get_index] == i)
        {
            // printf("%d\n", *iter);
            ret.push_back(*iter);
            get_index++;
            iter++;
            // printf("[%d]--\n", get_index);
        }

        multi_set.insert(inp[i]);

        if (iter == multi_set.end() || inp[i] < *iter)
        {
            iter--;
        }
    }

    while (get_index < pos.size() & pos[get_index] == inp.size())
    {
        // printf("%d\n", *iter);
        ret.push_back(*iter);
        iter++;
        get_index++;
    }
    return ret;
}

int main(int argc, char const *argv[])
{

    // freopen("./uva/inp/inp.txt", "r", stdin);

    int test;
    int m, n;
    scanf("%d", &test);
    while (test--)
    {

        scanf("%d %d", &m, &n);
        // printf("%d %d %d\n", test, n, m);
        vector<int> inp(m, 0);
        vector<int> pos(n, 0);

        for (int i = 0; i < m; i++)
            scanf("%d", &inp[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &pos[i]);
        
        auto ret = solve(inp, pos);
        for(int i = 0;i<ret.size();i++) {
            printf("%d\n", ret[i]);
        }
        if(test) {
            printf("\n");
        }
    }
    return 0;
}
