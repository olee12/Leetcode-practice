#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    map<string, int> timeDistance;
    vector<string> permutation;
    string nextClosestTime(string time) {
        for(int i =0; i < 24*60;i++) {
            char buff[7];
            snprintf(buff, 6 ,"%02d%02d", i/60, i % 60);
            timeDistance[string(buff)] = i;
        }
        string cur = "", tmp = "";
        for(char ch:time) {
            if(isdigit(ch)) cur.push_back(ch);
        }
        permutation.clear();
        rec(cur,tmp);
        // printf("permutation size: %d\n", permutation.size());

        int ret = 24*600;
        string finalTime = "";
        for(string &nxt: permutation) {
            int diff = timeDistance[nxt] - timeDistance[cur];
            if (diff <= 0) {
                diff = timeDistance["2359"] - timeDistance[cur];
                diff += timeDistance[nxt];
            }
            if (diff < ret) {
                ret = diff;
                finalTime = nxt;
            }
        }
        return finalTime.substr(0,2)+":"+finalTime.substr(2,2);
    }

    void rec(string &cur, string &tmp) {
        if(tmp.size()==cur.size()) {
            if(timeDistance.find(tmp)==timeDistance.end()) return ;
            permutation.push_back(tmp);
            return;
        }
        for(int i = 0;i<cur.length();i++) {
            tmp.push_back(cur[i]);
            rec(cur, tmp);
            tmp.pop_back();
        }
    } 
};



int main(int argc, char const *argv[])
{
    Solution sol;
    printf("%s\n", sol.nextClosestTime("23:59").c_str());
    return 0;
}
