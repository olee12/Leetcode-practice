#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
//olee12
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        dp[0] = 1;

        for(int coin:coins){
            for(int j = coin;j<=amount;j++){
                if(dp[j - coin]){
                    dp[j] = min(dp[j]?dp[j]:numeric_limits<int>::max(), dp[j-coin] + 1 );
                }
            }
        }
        if(dp[amount]) return dp[amount];
        else return -1;
    }
};




int main(){
    
}