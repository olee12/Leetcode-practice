#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

const int maxn = 100005;
int f[maxn];
int tmp[maxn];

vector<int> pos;
void kmp(int len1, int len2)
{

    int pt = 0;
    tmp[pt] = 0;
    for (int i = 1; i < len1; i++)
    {
        if (pattern[pt] == pattern[i])
            tmp[i++] = ++pt;
        else if (pt > 0)
            pt = tmp[pt - 1];
        else
            tmp[i++] = 0;
    }

    pt = 0;
    pos.clear();
    for (int i = 0; i < len2;)
    {
        if (pt < len1 && ((str[i] == pattern[pt]) || (str[i] == '?')))
            f[i++] = ++pt;
        else if (pt > 0)
            pt = tmp[pt - 1];
        else
            f[i++] = 0;
        if (pt == len1)
        {
            pos.push_back(i - 1);
        }
    }
}
string pattern;
string str;
bool compare(int pos)
{
    bool ret = true;
    int same = 0;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (str[i + pos] == '?')
        {
            same++;
            continue;
        }
        else if (str[i + pos] != pattern[i])
            return false;
    }
    if (same != pattern.length())
        return true;
    return false;
}

class Solution
{
  public:
    vector<int> movesToStamp(string stamp, string target)
    {
        pattern = stamp;
        str = target;

        int limit = 10 * target.size();
        deque<int> ret;
        int done = target.size();
        int prv = -1;

        while (prv != ret.size() && ret.size() < limit)
        {
            prv = ret.size();

            for (int i = 0; i <= str.size() - pattern.size(); i++)
            {
                if (compare(i))
                {
                    ret.push_front(i);
                    for (int x = 0; x < pattern.size(); x++)
                    {
                        done -= str[i + x] != '?';
                        str[i + x] = '?';
                    }
                }
            }
        }
        if (done == 0)
            return vector<int>{ret.begin(), ret.end()};
        return vector<int>();
    }
};

int main(int argc, char const *argv[])
{
    str = "ababc";
    pattern = "abc";

    // kmp(pattern.size(), str.size());

    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (i)
    //         printf("  ");
    //     printf("%d", i);
    // }
    // printf("\n");

    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (i)
    //         printf("  ");
    //     printf("%c", str[i]);
    // }
    // printf("\n");

    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (i)
    //         printf("  ");
    //     printf("%d", f[i]);
    // }
    // printf("\n");

    Solution sol;

    for (auto it : sol.movesToStamp(pattern, str))
    {
        printf(" [%d] ", it);
    };

    /* code */
    return 0;
}
