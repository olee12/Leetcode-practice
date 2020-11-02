#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        return getHintCool(secret, guess);
        int bull = 0;
        int cow = 0;
        map<char, int> ms, mg;
        ms.clear();
        mg.clear();
        for(int i = 0;i<secret.size();i++) {
            // if(i >= guess.size()) continue;
            if (secret[i]==guess[i]) {
                secret[i] = guess[i] = '-';
                bull++;
                continue;
            }
            ms[secret[i]]++;
            mg[guess[i]]++;

        }
        for (auto it : mg){
            cow += min(ms[it.first], it.second);
        }
        char buff[10];
        sprintf(buff, "%dA%dB", bull, cow);
        return string(buff);
    }

    string getHintCool(string &secret, string &guess) {
        int bull = 0;
        int cow = 0;
        int mp[10] = {0,0,0,0,0,0,0,0,0,0};

        for(int i = 0;i<secret.size();i++) {
            // if(i >= guess.size()) continue;
            if (secret[i]==guess[i]) {
                secret[i] = guess[i] = '-';
                bull++;
                continue;
            }
            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if (mp[s] < 0) cow++;
            if (mp[g] > 0) cow++;
            mp[s]++;
            mp[g]--;
           

        }
        char buff[10];
        sprintf(buff, "%dA%dB", bull, cow);
        return string(buff);
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    Solution sol;
    cout << sol.getHint("1123", "0111")<<endl;
    cout << sol.getHint("1", "1")<<endl;
    cout << sol.getHint("1807", "7810")<<endl;
    cout << sol.getHint("1", "0")<<endl;
    return 0;
}
