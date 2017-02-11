class Solution {
public:
    int reverse(int x) {
        long long a = (long long) x;
        int sign = x < 0;
        
        
        a = abs(a);
        long long my_ans = 0;
        while(a > 0){
            my_ans = my_ans*10 + a%10;
            a/=10;
        }
        if(sign == 1 && my_ans <= 2147483648) return (int)(my_ans*-1);
        else if(sign==0 && my_ans <= 2147483647) return (int)(my_ans);
        return 0;
    }
};