#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string countAndSay(int n)
    {
        char str[10000];
        string tmp = "1";
        string next = "";
        int nth = 1;
        while (nth < n)
        {

            int len = tmp.size();
            int i = 0, cnt = 0;
            while (i < len)
            {
                int j = i + 1;
                cnt = 1;
                while (j < len && tmp[i] == tmp[j])
                    cnt++, j++;

                sprintf(str, "%d", cnt);
                next += str;
                next += tmp[i];

                /*
                char *st = str;
                while(*st)
                next.push_back(*st++);

                next.push_back(tmp[i]);
                */

                i = j;
            }
            tmp = next;
            next = "";
            nth++;
        }
        return tmp;
    }
};

int main()
{
    Solution *sol = new Solution;
    for (int i = 1; i < 11; i++)
    {
        printf("%d %s\n", i, sol->countAndSay(i).c_str());
    }
    return 0;
}