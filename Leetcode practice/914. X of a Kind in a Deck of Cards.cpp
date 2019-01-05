#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int __gcd(int a, int b)
{
    if (b == 0)
        return a;
    a %= b;
    return __gcd(b, a);
}
class Solution
{
  public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        vector<int> freq = vector<int>(10000, 0);
        for (int a : deck)
            freq[a]++;
        int gcd = -1;
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == 0)
                continue;
            gcd = gcd == -1 ? freq[i] : __gcd(freq[i], gcd);
        }
        return gcd != 1;
    }
};

int main()
{
}