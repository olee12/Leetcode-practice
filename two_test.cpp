#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int maxn = 200000 + 20;
int ara[maxn];
int result[maxn];
priority_queue<int> nums;
set<int> position;
unordered_map<int,int> mm;
unordered_map<int,bool> flag;
int main()
{
    // freopen("./inp.txt","r",stdin);
    int n, k;

    while (scanf("%d %d", &n, &k) == 2)
    {
        while(nums.size()) nums.pop();
        position.clear();
        flag.clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", ara + i);
            nums.push(ara[i]);
            position.insert(i);
            mm[ara[i]] = i;

        }
        int team = 0;
        vector<int> del;
        while (nums.size())
        {
            if(flag[nums.top()]){
                nums.pop();
                continue;
            }
            pii current = make_pair(nums.top(),mm[nums.top()]);
            nums.pop();
            int cnt = 0;    
            int leftFlag = 1;
            for (int i = 0; i <= k; i++)
            {
                del.clear();
                if (position.size() == 0)
                    break;
                if (position.size())
                {
                    auto pos = position.lower_bound(current.second);
                    if (pos == position.end())
                    {
                        --pos;
                        leftFlag = 0;
                    }
                    del.push_back(*pos);
                    if (i > 0)
                    {
                        if (leftFlag && pos != position.begin())
                        {
                            --pos;
                            del.push_back(*pos);
                        }
                    }
                }
                for (int i = 0;i<del.size();i++)
                {
                    position.erase(del[i]);
                    result[del[i]] = team + 1;
                    flag[ara[del[i]]] = true;
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