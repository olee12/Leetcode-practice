#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
  public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<int> freq = vector<int>(26, 0);
        int dict[26];

        for (string &str : B)
        {
            memset(dict, 0, sizeof(dict));
            for (const char &ss : str)
            {
                const int &ch = ss - 'a';
                dict[ch]++;
            }
            for (const char &ss : str)
            {
                const int &ch = ss - 'a';
                if (dict[ch] > freq[ch])
                    freq[ch] = dict[ch];
            }
        }
        vector<string> ret;
        for (string &str : A)
        {
            bool flag = true;
            memset(dict, 0, sizeof(dict));
            for (const char &ss : str)
            {
                const int &ch = ss - 'a';
                dict[ch]++;
            }
            for (int i = 0; i < freq.size(); i++)
            {
                if (freq[i] == 0)
                    continue;
                flag &= (dict[i] >= freq[i]);
            }
            if (flag)
                ret.push_back(str);
        }
        return ret;
    }
};
int main()
{
}