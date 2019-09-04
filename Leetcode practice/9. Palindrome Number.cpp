#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        // cout<<"[ "<<str<<" ] ";
        for(int i = 0,j = str.size() - 1; i<j;i++,j--){
            if(str[i]!=str[j]) return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << "123: " << sol.isPalindrome(123) << endl;
    cout << "121: " << sol.isPalindrome(121) << endl;
    cout << "-121: " << sol.isPalindrome(-121) << endl;
    cout << "+134431: " << sol.isPalindrome(+134431) << endl;
    cout << "12321: " << sol.isPalindrome(12321) << endl;
}