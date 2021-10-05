#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        long long mod = 1000000007;
        long long lcm = a * b / __gcd(a, b);
        int m = lcm / a + lcm / b - 1;
        int q = n / m;
        int r = n % m;

        ;
        if (r == 0)
        {
            return (lcm * q) % mod;
        }
        int x = min(a, b);
        int y = max(a, b);
        vector<int> rest = {x, y};
        for (int i = 1; i < r; i++)
        {
            if (rest[0] < rest[1])
                rest[0] += x;
            else
                rest[1] += y;
        }

        long long ans = (lcm * q) % mod;
        ans = (ans + min(rest[0], rest[1])) % mod;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.nthMagicalNumber(10, 3, 8) << endl;

    return 0;
}
