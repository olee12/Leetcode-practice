#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int base = 1;
        int ret = 0;
        for(int i = s.size()-1;i>=0;i--){
            ret += base * (s[i]-'A' + 1);
            base *= 26;
        }
        return ret;
    }
};



int main() {
    Solution sol;
    cout << sol.titleToNumber("A") << endl;
    cout << sol.titleToNumber("AB") << endl;
}