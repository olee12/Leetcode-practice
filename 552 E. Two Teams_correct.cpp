#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int maxn = 200000 + 20;
int ara[maxn];
int result[maxn];
set<pii> nums;
set<int> position;

int main()
{
    // freopen("./inp.txt","r",stdin);
    int n, k;

    while (scanf("%d %d", &n, &k) == 2)
    {
        nums.clear();
        position.clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", ara + i);
            nums.insert(make_pair(ara[i], i));
            position.insert(i);
        }
        int team = 0;
        while (nums.size())
        {
            pii current = *nums.rbegin();
            vector<int> del;
            int leftFlag = 1;
            for (int i = 0; i <= k; i++)
            {
                del.clear();
                if (position.size() == 0)
                    break;
                if (position.size())
                {
                    set<int>::iterator pos = position.lower_bound(current.second);
                    if (pos == position.end())
                    {
                        pos--;
                        leftFlag = 0;
                    }
                    del.push_back(*pos);
                    result[*pos] = team + 1;
                    nums.erase(make_pair(ara[*pos], *pos));
                    if (i > 0)
                    {
                        if (leftFlag && pos != position.begin())
                        {
                            pos--;
                            del.push_back(*pos);
                            result[*pos] = team + 1;
                            nums.erase(make_pair(ara[*pos], *pos));
                        }
                    }
                }
                for (auto val : del)
                {
                    position.erase(val);
                }
            }
            team ^= 1;
        }

        for (int i = 1; i <= n; i++)
        {
            printf("%d", result[i]);
        }
        printf("\n");
    }
}