#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void reverseWords(string &s)
    {
        string &str = s;
        int len = str.size();
        int st = 0;
        int end = len - 1;
        reverseSt(str, st, end);
        int idx = 0;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == ' ')
                continue;
            st = i;
            end = i;
            while (end < len && str[end] != ' ')
                end++;
            end--;
            reverseSt(str, st, end);
            if(idx!=0){
                str[idx++] = ' ';
            }
            for (int j = st; j <= end; j++)
            {
                str[idx++] = str[j];
            }
            i = end;
        }
        str.erase(str.begin() + idx , str.end());
    }
    void reverseSt(string &str, int st, int end)
    {
        while (st < end)
        {
            char tmp = str[st];
            str[st] = str[end];
            str[end] = tmp;
            st++;
            end--;
        }
    }
};

int main()
{
    Solution sol;
    string str = string("   a     c     ");
    sol.reverseWords(str);
    printf("%s\n",str.c_str());
}