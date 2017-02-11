#include <limits.h>
class Solution {
public:
    int myAtoi(string str) {
        const char *s = str.c_str();
        int i = 0;
        int ret = 0;
        while(s[i]==' ') i++;
        int sign = 1;
        if(s[i]=='+') sign = 1,i++;
        else if(s[i]=='-') sign = -1,i++;
        while(s[i]>='0' && s[i]<='9'){
            if(ret > INT_MAX/10 || (ret == INT_MAX/10 && s[i]-'0'>7)){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            ret = ret * 10 + s[i]-'0';
            i++;
        }
        return ret*sign;
    }
};