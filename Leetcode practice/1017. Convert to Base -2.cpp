#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string baseNeg2(int n) {
        string str = "";
        int base = -2;
        while (n != 0) {
            auto ret = div(n, base);
            if (ret.rem < 0) {
                ret.rem += (-base);
                ret.quot += 1;
            }
            n = ret.quot;
            str.push_back(ret.rem == 0 ? '0' : '1');
        }
        reverse(str.begin(), str.end());
        if (str.size() == 0) {
            return "0";
        }
        return str;
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
